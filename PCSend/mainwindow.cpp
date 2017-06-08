#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qextserialport/src/qextserialport.h"
#include "string.h"
#include <QThread>
#include <QFileDialog>
#include <QTextStream>
#include <QtCore/QString>
#include <QtCore/QFile>
#include <QtCore/QDebug>
#include <QtCore/QTextStream>
#include <qfontdatabase.h>


#define DELAY_MICROSEC 120
#define DELAY_BETWEEN_PLAYBACK_COMMANDS_MSEC 1000

int playBackDelayMS = DELAY_BETWEEN_PLAYBACK_COMMANDS_MSEC;
char PortNumber = '0';
int spinBox1 = 0;
int spinBox4 = DELAY_MICROSEC;
bool Motor1 = true;
char Direction1 = 'f';
QString CommandSet = "";
bool recording = false;
QextSerialPort * port  = NULL;
QString fileNames;
QString savePath;

class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //QFontDatabase::addApplicationFont(":/fonts/FUTRFW.TFF");
    //QFont font = QFont("Futurist Fixed-width",10,1);

    int id = QFontDatabase::addApplicationFont(":/fonts/arial.ttf");
    if(id == -1 ){
           qDebug("FONT NOT LOADED!!!!!!!!!!!");
    }
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont font(family);

    int p = 0;
    //Find out which USB Port the send arduino is connected to
    bool b = false;
    while(!b && p < 20){
        PortNumber = (char)(p + 48);

    std::string str = "";
    QString qstr = QString::fromStdString(str);

    QString device = "/dev/ttyUSB";
    device.append(PortNumber);
    port = new QextSerialPort(device.toUtf8());

    port->setBaudRate(BAUD57600);
    port->setFlowControl(FLOW_OFF);

    port->setParity(PAR_EVEN);

    port->setDataBits(DATA_8);
    port->setStopBits(STOP_1);
    //port->setTimeout(0);
    port->setTimeout(100);

    bool res = false;
    res = port->open(QIODevice::ReadWrite | QIODevice::Unbuffered);

    ui->setupUi(this);

    if(res)
    {
        b = true;
        qDebug("Found port");
        ui->textBrowser_2->setText("Send arduino found.");
        ui->spinBox_3->setValue(PortNumber - 48);

    }
    else
    {
        p++;
        qDebug("Trying another port");
        ui->textBrowser_2->setText("Send arduino not found on any USB port!");

       }
    }

    //Set default GUI values
    ui->spinBox_4->setValue(DELAY_MICROSEC);
    ui->PlayBackDelaySpinBox->setValue(playBackDelayMS);

    ui->pushButton->setFont(font);
    ui->spinBox_4->setFont(font);

    setFixedSize(this->width(),this->height());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

       QChar MotorId = 'a';
       QString spinBox1String = QString::number(spinBox1);       
       QString speedString = QString::number(spinBox4);

       QString Command = speedString;
       Command.prepend(':');
       for(int i = 0; i < spinBox1String.length(); i++){
           Command.prepend(spinBox1String.at(spinBox1String.length() - 1 - i));
       }

       Command.prepend(Direction1);


       Command.prepend(MotorId);

       if(recording){
           CommandSet.append(Command);
           QString newLine = "\n";
           CommandSet.append(newLine);
           ui->textBrowser->setText(CommandSet);
        }


       //char data[Command.length()] = {};
       char * data;
       data = new char(Command.length());
        for(int i = 0; i < Command.length(); i++){
            data[i] = Command.at(i).toLatin1();
        }
        qDebug(Command.toLatin1());

        port->write(data, Command.length());

}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    spinBox1 = arg1;
}


void MainWindow::on_spinBox_3_valueChanged(int arg1)
{
    PortNumber = (char)(arg1 + 48);
    port->close();


    QFontDatabase::addApplicationFont(":/fonts/fonts/FUTRFW.TFF");
    QFont font = QFont("FUTRFW",10,1);
    this->setFont(font);

    std::string str = "";
    QString qstr = QString::fromStdString(str);

    QString device = "/dev/ttyUSB";
    device.append(PortNumber);
    port = new QextSerialPort(device.toUtf8());

    port->setBaudRate(BAUD9600);
    port->setFlowControl(FLOW_OFF);
    port->setParity(PAR_ODD);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_2);
    port->setTimeout(0);
    bool res = false;
    res = port->open(QIODevice::ReadWrite | QIODevice::Unbuffered);

    if(res)
    {

        qDebug("Connection created");
        ui->textBrowser_2->setText("Send arduino found!");


    }
    else{

        qDebug("Failed to connect");
        ui->textBrowser_2->setText("Send arduino NOT found on this port");

       }
    }


void MainWindow::on_pushButton_3_clicked()
{
    //the clear Button
    CommandSet = "";
    ui->textBrowser->setText(CommandSet);
}

void MainWindow::on_checkBox_clicked(bool checked)
{
    recording = checked;
}

void MainWindow::on_pushButton_4_clicked()
{
    //the Play Button
    QString tempCommand = "";
    for(int i = 0; i < CommandSet.length(); i++){
        if(CommandSet.at(i).toLatin1() == '\n'){
            char* data;
            data = new char(tempCommand.length());
            for(int i = 0; i < tempCommand.length(); i++){
                data[i] = tempCommand.at(i).toLatin1();
            }
            port->write(data, tempCommand.length());
            tempCommand = "";
            if(i != CommandSet.length() -1){
                 Sleeper::msleep(playBackDelayMS);
            }
            continue;
        }
        tempCommand.append(CommandSet.at(i).toLatin1());
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    //Save a copy button
    savePath = QFileDialog::getSaveFileName(this, tr("Save a Copy"),"/path/to/file/",tr(""));


    /* Try and open a file for output */
    QString outputFilename = savePath;
    QFile outputFile(outputFilename);
    outputFile.open(QIODevice::WriteOnly);

    /* Check it opened OK */
    if(!outputFile.isOpen()){
        ui->textBrowser_2->clear();
        ui->textBrowser_2->setText("Could not Save to file");
        return;
    }

    /* Point a QTextStream object at the file */
    QTextStream outStream(&outputFile);

    /* Write the line to the file */
    outStream << CommandSet;

    /* Close the file */
    outputFile.close();
    ui->textBrowser_2->setText("Saved to " + savePath);


}

void MainWindow::on_pushButton_6_clicked()
{
    //The Load Button
    fileNames = QFileDialog::getOpenFileName(this, tr("Open File"),"/path/to/file/",tr(""));
    //fileNames = QFileDialog::getSaveFileName(this, tr("Save as"),"/path/to/file/",tr(""));

    ui->listWidget->clear();
    ui->listWidget->addItem(fileNames);

    QFile f1(fileNames);

    f1.open(QIODevice::ReadOnly | QIODevice::Text);

    QString s;

    QTextStream s1(&f1);

    while (!s1.atEnd()){
        s.append(s1.readLine());
        s.append('\n');
       // if (i != 2)s.append("\n");
    }
    qDebug(s.toLatin1());
    CommandSet = s;
    ui->textBrowser->setText(CommandSet);
}

void MainWindow::on_pushButton_7_clicked()
{
    //Save As button
    savePath = QFileDialog::getSaveFileName(this, tr("Save as"),"/path/to/file/",tr(""));
    fileNames = savePath;
    ui->listWidget->clear();
    ui->listWidget->addItem(fileNames);

    /* Try and open a file for output */
    QString outputFilename = savePath;
    QFile outputFile(outputFilename);
    outputFile.open(QIODevice::WriteOnly);

    /* Check it opened OK */
    if(!outputFile.isOpen()){
        ui->textBrowser_2->clear();
        ui->textBrowser_2->setText("Could not Save to file");
        return;
    }

    /* Point a QTextStream object at the file */
    QTextStream outStream(&outputFile);

    /* Write the line to the file */
    outStream << CommandSet;

    /* Close the file */
    outputFile.close();
    ui->textBrowser_2->setText("Saved to " + savePath);


}

void MainWindow::on_pushButton_8_clicked()
{
    //Save button
    savePath = fileNames;


    /* Try and open a file for output */
    QString outputFilename = savePath;
    QFile outputFile(outputFilename);
    outputFile.open(QIODevice::WriteOnly);

    /* Check it opened OK */
    if(!outputFile.isOpen()){
        ui->textBrowser_2->clear();
        ui->textBrowser_2->setText("Could not Save to file");
        return;
    }

    /* Point a QTextStream object at the file */
    QTextStream outStream(&outputFile);

    /* Write the line to the file */
    outStream << CommandSet;

    /* Close the file */
    outputFile.close();
    ui->textBrowser_2->setText("Saved to " + savePath);

}


void MainWindow::on_spinBox_4_valueChanged(int arg1)
{
    spinBox4 = arg1;
}

void MainWindow::on_PlayBackDelaySpinBox_valueChanged(int arg1)
{
    playBackDelayMS = arg1;
}
