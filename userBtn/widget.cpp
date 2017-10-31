#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    btn=new QPushButton(this);
    QString css = "QPushButton{text:red;background-color:yellow;}";
    btn->setStyleSheet(css);
}

Widget::~Widget()
{
    delete ui;
}
