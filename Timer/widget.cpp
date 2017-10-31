#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    time = new QTimer();
    id = this->startTimer(1000);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::timerEvent(QTimerEvent *event)
{
    int static sec = 0;
    sec++;
    qDebug()<<sec;
    QString str = (QString)sec;
    ui->label->setText(str);
}
