/********************************************************************************
** Form generated from reading UI file 'zamekapp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZAMEKAPP_H
#define UI_ZAMEKAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ZamekApp
{
public:
    QWidget *centralWidget;
    QPushButton *serialRefreshButton;
    QComboBox *serialComboBox;
    QLabel *serialLabel;
    QLabel *serialStatusLabel;
    QTextBrowser *debugTextBrowser;
    QLineEdit *userLineEdit;
    QLineEdit *siteLineEdit;
    QLineEdit *passLineEdit;
    QSpinBox *entryNumberSpinBox;
    QPushButton *restoreButton;
    QPushButton *backupButton;
    QPushButton *saveButton;
    QLabel *entryNumberLabel;
    QLabel *portExplainLabel;
    QLabel *backupExplainLabel;
    QLabel *editExplainLabel;
    QLabel *siteLabel;
    QLabel *userLabel;
    QLabel *passLabel;
    QFrame *portBackupLine;
    QFrame *backupEditLine;
    QLabel *lockStatusLabel;
    QPushButton *lockRefreshButton;
    QPushButton *loadButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ZamekApp)
    {
        if (ZamekApp->objectName().isEmpty())
            ZamekApp->setObjectName(QStringLiteral("ZamekApp"));
        ZamekApp->resize(400, 800);
        centralWidget = new QWidget(ZamekApp);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        serialRefreshButton = new QPushButton(centralWidget);
        serialRefreshButton->setObjectName(QStringLiteral("serialRefreshButton"));
        serialRefreshButton->setGeometry(QRect(200, 34, 80, 24));
        serialComboBox = new QComboBox(centralWidget);
        serialComboBox->setObjectName(QStringLiteral("serialComboBox"));
        serialComboBox->setGeometry(QRect(90, 35, 100, 22));
        serialLabel = new QLabel(centralWidget);
        serialLabel->setObjectName(QStringLiteral("serialLabel"));
        serialLabel->setGeometry(QRect(14, 38, 75, 16));
        QFont font;
        font.setPointSize(10);
        serialLabel->setFont(font);
        serialStatusLabel = new QLabel(centralWidget);
        serialStatusLabel->setObjectName(QStringLiteral("serialStatusLabel"));
        serialStatusLabel->setGeometry(QRect(290, 38, 111, 16));
        serialStatusLabel->setFont(font);
        serialStatusLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        debugTextBrowser = new QTextBrowser(centralWidget);
        debugTextBrowser->setObjectName(QStringLiteral("debugTextBrowser"));
        debugTextBrowser->setGeometry(QRect(0, 340, 391, 350));
        userLineEdit = new QLineEdit(centralWidget);
        userLineEdit->setObjectName(QStringLiteral("userLineEdit"));
        userLineEdit->setGeometry(QRect(260, 266, 115, 21));
        siteLineEdit = new QLineEdit(centralWidget);
        siteLineEdit->setObjectName(QStringLiteral("siteLineEdit"));
        siteLineEdit->setGeometry(QRect(260, 226, 115, 21));
        passLineEdit = new QLineEdit(centralWidget);
        passLineEdit->setObjectName(QStringLiteral("passLineEdit"));
        passLineEdit->setGeometry(QRect(260, 306, 115, 21));
        entryNumberSpinBox = new QSpinBox(centralWidget);
        entryNumberSpinBox->setObjectName(QStringLiteral("entryNumberSpinBox"));
        entryNumberSpinBox->setGeometry(QRect(106, 227, 43, 22));
        entryNumberSpinBox->setFont(font);
        entryNumberSpinBox->setMinimum(1);
        entryNumberSpinBox->setMaximum(64);
        restoreButton = new QPushButton(centralWidget);
        restoreButton->setObjectName(QStringLiteral("restoreButton"));
        restoreButton->setGeometry(QRect(239, 110, 121, 28));
        backupButton = new QPushButton(centralWidget);
        backupButton->setObjectName(QStringLiteral("backupButton"));
        backupButton->setGeometry(QRect(40, 110, 121, 28));
        backupButton->setStyleSheet(QStringLiteral(""));
        backupButton->setFlat(false);
        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(20, 310, 131, 21));
        entryNumberLabel = new QLabel(centralWidget);
        entryNumberLabel->setObjectName(QStringLiteral("entryNumberLabel"));
        entryNumberLabel->setGeometry(QRect(20, 230, 91, 16));
        entryNumberLabel->setFont(font);
        portExplainLabel = new QLabel(centralWidget);
        portExplainLabel->setObjectName(QStringLiteral("portExplainLabel"));
        portExplainLabel->setGeometry(QRect(0, 5, 400, 20));
        portExplainLabel->setFont(font);
        portExplainLabel->setAlignment(Qt::AlignCenter);
        backupExplainLabel = new QLabel(centralWidget);
        backupExplainLabel->setObjectName(QStringLiteral("backupExplainLabel"));
        backupExplainLabel->setGeometry(QRect(0, 80, 400, 20));
        backupExplainLabel->setFont(font);
        backupExplainLabel->setAlignment(Qt::AlignCenter);
        editExplainLabel = new QLabel(centralWidget);
        editExplainLabel->setObjectName(QStringLiteral("editExplainLabel"));
        editExplainLabel->setGeometry(QRect(0, 155, 400, 20));
        editExplainLabel->setFont(font);
        editExplainLabel->setAlignment(Qt::AlignCenter);
        siteLabel = new QLabel(centralWidget);
        siteLabel->setObjectName(QStringLiteral("siteLabel"));
        siteLabel->setGeometry(QRect(220, 230, 47, 13));
        siteLabel->setFont(font);
        userLabel = new QLabel(centralWidget);
        userLabel->setObjectName(QStringLiteral("userLabel"));
        userLabel->setGeometry(QRect(220, 270, 47, 13));
        userLabel->setFont(font);
        passLabel = new QLabel(centralWidget);
        passLabel->setObjectName(QStringLiteral("passLabel"));
        passLabel->setGeometry(QRect(220, 310, 47, 13));
        passLabel->setFont(font);
        portBackupLine = new QFrame(centralWidget);
        portBackupLine->setObjectName(QStringLiteral("portBackupLine"));
        portBackupLine->setGeometry(QRect(-3, 61, 411, 20));
        portBackupLine->setFrameShape(QFrame::HLine);
        portBackupLine->setFrameShadow(QFrame::Sunken);
        backupEditLine = new QFrame(centralWidget);
        backupEditLine->setObjectName(QStringLiteral("backupEditLine"));
        backupEditLine->setGeometry(QRect(0, 138, 411, 20));
        backupEditLine->setFrameShape(QFrame::HLine);
        backupEditLine->setFrameShadow(QFrame::Sunken);
        lockStatusLabel = new QLabel(centralWidget);
        lockStatusLabel->setObjectName(QStringLiteral("lockStatusLabel"));
        lockStatusLabel->setGeometry(QRect(70, 187, 120, 16));
        lockStatusLabel->setFont(font);
        lockStatusLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lockRefreshButton = new QPushButton(centralWidget);
        lockRefreshButton->setObjectName(QStringLiteral("lockRefreshButton"));
        lockRefreshButton->setGeometry(QRect(200, 185, 80, 22));
        loadButton = new QPushButton(centralWidget);
        loadButton->setObjectName(QStringLiteral("loadButton"));
        loadButton->setGeometry(QRect(20, 270, 131, 21));
        ZamekApp->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ZamekApp);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ZamekApp->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        serialLabel->setBuddy(serialComboBox);
        entryNumberLabel->setBuddy(entryNumberSpinBox);
        siteLabel->setBuddy(siteLineEdit);
        userLabel->setBuddy(userLineEdit);
        passLabel->setBuddy(passLineEdit);
        lockStatusLabel->setBuddy(lockRefreshButton);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(serialComboBox, serialRefreshButton);
        QWidget::setTabOrder(serialRefreshButton, backupButton);
        QWidget::setTabOrder(backupButton, restoreButton);
        QWidget::setTabOrder(restoreButton, lockRefreshButton);
        QWidget::setTabOrder(lockRefreshButton, entryNumberSpinBox);
        QWidget::setTabOrder(entryNumberSpinBox, loadButton);
        QWidget::setTabOrder(loadButton, saveButton);
        QWidget::setTabOrder(saveButton, siteLineEdit);
        QWidget::setTabOrder(siteLineEdit, userLineEdit);
        QWidget::setTabOrder(userLineEdit, passLineEdit);
        QWidget::setTabOrder(passLineEdit, debugTextBrowser);

        retranslateUi(ZamekApp);

        QMetaObject::connectSlotsByName(ZamekApp);
    } // setupUi

    void retranslateUi(QMainWindow *ZamekApp)
    {
        ZamekApp->setWindowTitle(QApplication::translate("ZamekApp", "ZamekApp", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        serialRefreshButton->setToolTip(QApplication::translate("ZamekApp", "<html><head/><body><p>Refresh list of currently available Serial Ports</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        serialRefreshButton->setText(QApplication::translate("ZamekApp", "Refresh", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        serialComboBox->setToolTip(QApplication::translate("ZamekApp", "<html><head/><body><p>Try unplugging your Zamek and clicking Refresh, checking the ports that are still in the dropdown list while it is unplugged, then plug the Zamek back in and click Refresh, and select the new Serial Port listing that appears</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        serialLabel->setText(QApplication::translate("ZamekApp", "Zamek Port:", Q_NULLPTR));
        serialStatusLabel->setText(QApplication::translate("ZamekApp", "Connection", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        restoreButton->setToolTip(QApplication::translate("ZamekApp", "<html><head/><body><p>Restores the encrypted contents of your Zamek Memory Chip from a file on your computer</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        restoreButton->setText(QApplication::translate("ZamekApp", "Restore", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        backupButton->setToolTip(QApplication::translate("ZamekApp", "<html><head/><body><p>Stores the encrypted contents of your Zamek Memory Chip to a file on your computer</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        backupButton->setText(QApplication::translate("ZamekApp", "Backup", Q_NULLPTR));
        saveButton->setText(QApplication::translate("ZamekApp", "Save Entry", Q_NULLPTR));
        entryNumberLabel->setText(QApplication::translate("ZamekApp", "Entry Number:", Q_NULLPTR));
        portExplainLabel->setText(QApplication::translate("ZamekApp", "Please select the Serial Port your Zamek is connected to:", Q_NULLPTR));
        backupExplainLabel->setText(QApplication::translate("ZamekApp", "Backup and Restore your Zamek's Memory Chip to your computer:", Q_NULLPTR));
        editExplainLabel->setText(QApplication::translate("ZamekApp", "Unlock your Zamek on the device using your PIN to Edit Entries:", Q_NULLPTR));
        siteLabel->setText(QApplication::translate("ZamekApp", "Site:", Q_NULLPTR));
        userLabel->setText(QApplication::translate("ZamekApp", "User:", Q_NULLPTR));
        passLabel->setText(QApplication::translate("ZamekApp", "Pass:", Q_NULLPTR));
        lockStatusLabel->setText(QApplication::translate("ZamekApp", "Zamek is Locked", Q_NULLPTR));
        lockRefreshButton->setText(QApplication::translate("ZamekApp", "Refresh", Q_NULLPTR));
        loadButton->setText(QApplication::translate("ZamekApp", "Load Entry", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ZamekApp: public Ui_ZamekApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZAMEKAPP_H
