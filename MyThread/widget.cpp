#include "widget.h"
#include "ui_widget.h"
#include<QThread>
#include<QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mytimer = new QTimer(this);
    myt = new Mythread(this);
    connect(mytimer,&QTimer::timeout,this,
            [=]()
    {
        static int i = 0;
        i++;
        ui->lcdNumber->display(i);

    }
    );
    connect(myt,&Mythread::dealRunOK,
            [=]()
    {
        myt->quit();
        qDebug()<<"finish";
        mytimer->stop();
    }
    );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    mytimer->start(100);
    myt->start();
    //QThread::sleep(5);
    //mytimer->stop();
}
