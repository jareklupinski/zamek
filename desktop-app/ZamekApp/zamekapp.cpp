#include "zamekapp.h"
#include "ui_zamekapp.h"

//TODO set platform-dependant icons: http://doc.qt.io/qt-4.8/appicon.html

ZamekApp::ZamekApp( QWidget *parent ) : QMainWindow( parent ), ui( new Ui::ZamekApp ) {
    ui->setupUi( this );
    serial = new QSerialPort( this );
    serial->close();
    connect( serial, static_cast< void ( QSerialPort::* )( QSerialPort::SerialPortError )> ( &QSerialPort::error ), this, &ZamekApp::handleError);
    foreach ( const QSerialPortInfo &info, QSerialPortInfo::availablePorts() ) ui->serialComboBox->addItem( info.portName() );
}

void ZamekApp::disableControls() {
    ui->loadButton->setEnabled(false);
    ui->saveButton->setEnabled(false);
    ui->backupButton->setEnabled(false);
    ui->restoreButton->setEnabled(false);
    ui->entryNumberSpinBox->setEnabled(false);
    ui->lockStatusLabel->setText("Zamek is Locked");
    ui->siteLineEdit->setEnabled(false);
    ui->userLineEdit->setEnabled(false);
    ui->passLineEdit->setEnabled(false);
    ui->siteLineEdit->setText("");
    ui->userLineEdit->setText("");
    ui->passLineEdit->setText("");
}

void ZamekApp::enableControls() {
    ui->serialStatusLabel->setText( "Connecting..." );
    QByteArray msg = "*v";
    QByteArray response = getSerialData( msg );
    if ( response[ 0 ] == '@' ) {
        ui->serialStatusLabel->setText( "Connected" );
        ui->backupButton->setEnabled(true);
        ui->restoreButton->setEnabled(true);
    }
    if ( response[ 1 ] == 'U' ) {
        ui->loadButton->setEnabled(true);
        ui->saveButton->setEnabled(true);
        ui->lockStatusLabel->setText("Zamek is Unlocked");
        ui->entryNumberSpinBox->setEnabled(true);
        ui->siteLineEdit->setEnabled(true);
        ui->userLineEdit->setEnabled(true);
        ui->passLineEdit->setEnabled(true);
    }
}

QByteArray ZamekApp::getSerialData( const QByteArray &msg ) {
    ui->statusBar->showMessage(tr( "Reading Zamek Data..." ));
    serial->close();
    QByteArray responseData;
    serial->setPortName( ui->serialComboBox->currentText() );
    if (serial->open( QIODevice::ReadWrite )){
        serial->setDataTerminalReady(true);
        serial->flush();
        serial->clear();
        serial->write( msg );
        while (serial->waitForReadyRead( 2000 )) responseData += serial->readAll();
        ui->debugTextBrowser->setText(responseData);
    }
    else ui->statusBar->showMessage(tr( "Critical Error" ));
    serial->flush();
    serial->clear();
    serial->close();
    return responseData;
}

void ZamekApp::handleError(QSerialPort::SerialPortError error) {
    if (error == QSerialPort::ResourceError) {
        ui->statusBar->showMessage(tr("Critical Error"));
        serial->close();
    }
}

ZamekApp::~ZamekApp() {
    delete ui;
}

void ZamekApp::on_serialRefreshButton_clicked() {
    ui->serialComboBox->clear();
    foreach ( const QSerialPortInfo &info, QSerialPortInfo::availablePorts() ) ui->serialComboBox->addItem( info.portName() );
}

void ZamekApp::on_serialComboBox_currentIndexChanged() {
    disableControls();
    ui->debugTextBrowser->clear();
    enableControls();
}

void ZamekApp::on_backupButton_clicked() {
    //TODO dump twice and compare
    disableControls();
    QByteArray msg = "*d";
    QByteArray response = getSerialData( msg );
    if ( response[ 1 ] == 'd' ){
        response.remove( 0, 2 );
        QString fileName = QFileDialog::getSaveFileName( this, "Save Zamek Backup To...", "","Zamek Backup (*.zmk);;All Files (*)" );
        if ( fileName.isEmpty() ) ui->statusBar->showMessage(tr( "No File Specified" ));
        else {
            QFile file(fileName);
            if (!file.open(QIODevice::WriteOnly)) {
                ui->statusBar->showMessage(tr( "Can't Open File for Writing" ));
            }
            else {
                file.write( response );
                ui->statusBar->showMessage(tr( "Zamek Dumped" ));
            }
        }
    }
    else ui->statusBar->showMessage(tr( "Bad Dump" ));
    enableControls();
}

void ZamekApp::on_restoreButton_clicked() {
    //TODO dump and compare to original
    disableControls();
    QString filename = QFileDialog::getOpenFileName( this, "Restore Zamek Backup From...", "","Zamek Backup (*.zmk);;All Files (*)" );
    if ( filename.isEmpty() ) ui->statusBar->showMessage( "No File Selected" );
    else {
        QFile file( filename );
        if ( !file.open(QIODevice::ReadOnly) ) ui->statusBar->showMessage( "Can't Open File for Reading" );
        else {
            QByteArray msg = "*u";
            msg.append( file.readAll() );
            QByteArray response = getSerialData( msg );
        }
    }
    enableControls();
}

void ZamekApp::on_lockRefreshButton_clicked() {
    on_serialComboBox_currentIndexChanged();
}

void ZamekApp::on_entryNumberSpinBox_valueChanged() {
    on_loadButton_clicked();
}

void ZamekApp::on_loadButton_clicked() {
    //TODO download twice and verify
    disableControls();
    QByteArray msg = "*r";
    msg.append( QString::number( ui->entryNumberSpinBox->value() ) );
    QByteArray response = getSerialData( msg );
    if ( response[ 1 ] == 'r' ) {
        response.remove( 0, 2 );
        QString responseString = response;
        QStringList responseList = responseString.split( "\r\n" );
        ui->siteLineEdit->setText( responseList[ 0 ] );
        ui->userLineEdit->setText( responseList[ 1 ] );
        ui->passLineEdit->setText( responseList[ 2 ] );
    }
    else ui->statusBar->showMessage(tr( "Credentials Can't Be Read" ));
    enableControls();
}

void ZamekApp::on_saveButton_clicked() {
    //TODO read back to verify
    QString site = ui->siteLineEdit->text();
    int len = site.length();
    if ( len < 16 ) { for ( int i = 0; i < ( 16 - len ); i++ ) { site.append(' '); }}
    QString user = ui->userLineEdit->text();
    len = user.length();
    if ( len < 16 ) { for ( int i = 0; i < ( 16 - len ); i++ ) { user.append(' '); }}
    QString pass = ui->passLineEdit->text();
    len = pass.length();
    if ( len < 16 ) { for ( int i = 0; i < ( 16 - len ); i++ ) { pass.append(' '); }}
    disableControls();
    QByteArray msg = "*w";
    msg.append( QString::number( ui->entryNumberSpinBox->value() ) );
    msg.append( ';' );
    msg.append( site );
    msg.append( user );
    msg.append( pass );
    QByteArray response = getSerialData( msg );
    enableControls();
}
