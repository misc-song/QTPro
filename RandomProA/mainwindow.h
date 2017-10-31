#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"userinfo.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    QVector<UserInfo> users;//所有人
    QVector<UserInfo> male;//男
    QVector<UserInfo> female;//女
    int maleCount;//总的男生数
    int femaleCount;//总的女生数
    int classNum = 20;//组数
    int cmaleNum ;//每组中男生的个数
    int cfemaleNum;//每组中女生的个数
    int maleRemain;//分组后男生剩下的人数
    int femaleRemain;//分组后女生剩下的人数
     int CountBtn = 1;//
    //int random(int ra);//随机方法
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_O_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_action_V_triggered();

    void on_action_H_triggered();

    void on_action_X_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
