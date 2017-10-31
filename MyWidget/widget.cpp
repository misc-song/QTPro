#include "widget.h"



Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    btn.setText("press");
    btn.setParent(this);
    connect(&btn,&QPushButton::pressed,this,&Widget::GotoSub);
    connect(&sub,&SubWidget::EmitS,this,&Widget::RetuenMain);
}

Widget::~Widget()
{

}
void Widget::GotoSub()
{
    this->hide();
    sub.show();
}

void Widget::RetuenMain()
{
    this->show();
    sub.hide();
}
