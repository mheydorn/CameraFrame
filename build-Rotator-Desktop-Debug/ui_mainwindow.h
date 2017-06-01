/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QSpinBox *spinBox;
    QLabel *label;
    QSpinBox *spinBox_3;
    QLabel *label_3;
    QLabel *label_4;
    QTextBrowser *textBrowser;
    QCheckBox *checkBox;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QListWidget *listWidget;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QTextBrowser *textBrowser_2;
    QPushButton *pushButton_8;
    QLabel *label_6;
    QLabel *label_7;
    QSpinBox *spinBox_4;
    QLabel *label_8;
    QSpinBox *PlayBackDelaySpinBox;
    QLabel *label_9;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(491, 609);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(210, 40, 95, 31));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(130, 40, 71, 31));
        spinBox->setMinimum(-10000);
        spinBox->setMaximum(10000);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 281, 21));
        spinBox_3 = new QSpinBox(centralWidget);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setGeometry(QRect(410, 40, 52, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(330, 40, 67, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 40, 111, 21));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(120, 180, 351, 121));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(20, 180, 95, 26));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 220, 95, 31));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 260, 95, 31));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(370, 400, 101, 31));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(120, 320, 351, 51));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(20, 400, 95, 31));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(260, 400, 95, 31));
        textBrowser_2 = new QTextBrowser(centralWidget);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(120, 460, 351, 51));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(140, 400, 101, 31));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 330, 101, 21));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 470, 91, 21));
        spinBox_4 = new QSpinBox(centralWidget);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setGeometry(QRect(220, 90, 91, 31));
        spinBox_4->setMaximum(99999);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 90, 191, 21));
        PlayBackDelaySpinBox = new QSpinBox(centralWidget);
        PlayBackDelaySpinBox->setObjectName(QStringLiteral("PlayBackDelaySpinBox"));
        PlayBackDelaySpinBox->setGeometry(QRect(280, 140, 91, 31));
        PlayBackDelaySpinBox->setMaximum(99999);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 140, 261, 21));
        MainWindow->setCentralWidget(centralWidget);
        spinBox->raise();
        pushButton->raise();
        label->raise();
        spinBox_3->raise();
        label_3->raise();
        label_4->raise();
        textBrowser->raise();
        checkBox->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        listWidget->raise();
        pushButton_6->raise();
        pushButton_7->raise();
        textBrowser_2->raise();
        pushButton_8->raise();
        label_6->raise();
        label_7->raise();
        spinBox_4->raise();
        label_8->raise();
        PlayBackDelaySpinBox->raise();
        label_9->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 491, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Go", 0));
#ifndef QT_NO_TOOLTIP
        spinBox->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Sets the number of degrees that the turn table will turn each time Go is pressed.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "Camera Frame Controller", 0));
#ifndef QT_NO_TOOLTIP
        spinBox_3->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>The USB port of the transmitter. Usually from 0 to 5. </p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label_3->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>The USB port of the transmitter. Usually from 0 to 5. </p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("MainWindow", "USB Port", 0));
        label_4->setText(QApplication::translate("MainWindow", "Angle To Move", 0));
        checkBox->setText(QApplication::translate("MainWindow", "Recording", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Clear", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Play", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Save a Copy", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "Open File", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "Save As", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "Save", 0));
        label_6->setText(QApplication::translate("MainWindow", "Current File", 0));
        label_7->setText(QApplication::translate("MainWindow", "Notifications", 0));
        label_8->setText(QApplication::translate("MainWindow", "Delay Between Steps (\316\274sec)", 0));
        label_9->setText(QApplication::translate("MainWindow", "Delay Between Playback Steps (msec)", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
