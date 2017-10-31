#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QSqlDatabase db ;
    db.addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("student");
    bool ok = db.open();
    qDebug()<<ok;
    model = new QSqlTableModel();
    model->setTable("student");
    ui->tableView->setModel(model);
    model->select();


}

Widget::~Widget()
{
    delete ui;
}
