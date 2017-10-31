#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QFile>
#include<QFileDialog>
#include<QPushButton>
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

void Widget::on_pushButton_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this,"open","../","TXT(*.txt);;SQL(*.sql)");
    QFile file;
    file.setFileName(filepath);
    if(file.open(QIODevice::ReadOnly))
    {
        ui->textEdit->setText(file.readAll());
    }
    file.close();
}

void Widget::on_pushButton_2_clicked()
{
    QString filepath = QFileDialog::getSaveFileName(this,"save","../","TXT(*.txt);;SQL(*.sql)");
    QFile file;
    file.setFileName(filepath);
    if(file.open(QIODevice::WriteOnly))
    {
        file.write(ui->textEdit->toPlainText().toUtf8());
    }
    file.close();
}
