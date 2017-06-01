#define VERSION "This is the version with speed"
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_pushButton_3_clicked();

    void on_checkBox_clicked(bool checked);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_spinBox_4_valueChanged(int arg1);

    void on_PlayBackDelaySpinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
