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

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter p;
    p.begin(this);
    //画背景图
   // p.drawPixmap(0,0,width(),height(),QPixmap("../img/map.png"));
    p.drawPixmap(rect(),QPixmap("../img/map.png"));
    //画直线
    QPen pen;
    pen.setWidth(5);
    p.setPen(pen);
    p.drawLine(50,50,150,50);
    p.drawLine(50,50,50,150);

    p.end();
}
