#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    btn.setText("press");
    btn.setParent(this);
    connect(&btn,&QPushButton::pressed,this,
    [=]()
    {
        this->hide();
        sub.show();
    }
    );

    connect(&sub,&SubNew::EmitS,this,
    [=]()
    {
        this->show();
        sub.hide();
    }
    );

}

Widget::~Widget()
{

}
