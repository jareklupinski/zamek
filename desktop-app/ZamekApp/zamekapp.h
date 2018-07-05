#ifndef ZAMEKAPP_H
#define ZAMEKAPP_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QTSerialPort/QSerialPortInfo>
#include <QFileDialog>

namespace Ui {
class ZamekApp;
class QSerialPort;
class QFile;
}

class ZamekApp : public QMainWindow {
    Q_OBJECT

public:
    explicit ZamekApp( QWidget *parent = 0 );
    ~ZamekApp();

private slots:
    void handleError( QSerialPort::SerialPortError error );
    void on_serialRefreshButton_clicked();
    void on_serialComboBox_currentIndexChanged();
    void on_backupButton_clicked();
    void on_restoreButton_clicked();
    void on_lockRefreshButton_clicked();
    void on_entryNumberSpinBox_valueChanged();
    void on_loadButton_clicked();
    void on_saveButton_clicked();

private:
    Ui::ZamekApp *ui;
    QSerialPort *serial;
    QByteArray getSerialData( const QByteArray &msg );
    void disableControls();
    void enableControls();
};

#endif // ZAMEKAPP_H
