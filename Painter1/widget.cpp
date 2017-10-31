#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QPen>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

//重写绘图事件
void Widget::paintEvent(QPaintEvent *event)
{

    //    QPainter p;
    //    p.begin(this);//指定绘图设备
    //    //画笔的创建要 （放置于begin和end之间）
    //    QPen pen;
    //    pen.setColor(Qt::red);//设置画笔的颜色
    //    pen.setStyle(Qt::DashDotDotLine);//设置画笔的样式
    //    pen.setWidth(20);//设置画笔的粗细
    //    p.setPen(pen);//将画笔交给画家
    //    p.drawLine(QPoint(20,20),QPoint(200,200));//绘制一条直线
    //    //绘制方法 grawxxx();
    //    p.end();//结束


    QPen pen;
    QPainter p(this);//制定绘图设备 将内容绘制在当前的窗口中
    //画笔的创建要 （放置于begin和end之间）
    QPixmap pic("../img/map.png");
    p.drawPixmap(0,0,width(),height(),pic);
    pen.setColor(Qt::red);//设置画笔的颜色
    pen.setStyle(Qt::DashDotDotLine);//设置画笔的样式
    pen.setWidth(20);//设置画笔的粗细
    p.setPen(pen);//将画笔交给画家
    p.drawLine(QPoint(20,20),QPoint(200,200));//绘制一条直线
    //绘制方法 grawxxx();
    //p.end();//结束



}
