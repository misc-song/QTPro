#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //动态分配空间
    myT = new Mythread;
    //创建子线程
    thread = new QThread(this);
    myT->moveToThread(thread);//把自定义线程加入到子线程中
    connect(myT,&Mythread::mySingal,this,&Widget::dealSignal);
    qDebug()<<"主线程号"<<QThread::currentThread();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::dealSignal()
{
    static int i = 0;
    i++;
    ui->lcdNumber->display(i);
}
void Widget::on_startBtn_clicked()
{
    //启动线程 但是没有启动线程处理函数
    thread->start();
    myT->myTimeOut();
}

void Widget::on_stopBtn_clicked()
{

}
