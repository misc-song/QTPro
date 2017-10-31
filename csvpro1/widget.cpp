#include "widget.h"
#include "ui_widget.h"

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

void Widget::on_openBtn_clicked()
{

}

void Widget::on_createBtn_clicked()
{

}

void Widget::on_saveBtn_clicked()
{

}
