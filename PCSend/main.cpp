#include "mainwindow.h"
#include <QApplication>
#include <QtCore/QCoreApplication>
#include "qextserialport/src/qextserialport.h"
#include <qfontdatabase.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowTitle("Camera Frame Controller");

    w.show();

    return a.exec();
}
