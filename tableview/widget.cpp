#include "widget.h"
#include "ui_widget.h"
#include <QSqlError>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this);
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("my.db");
    //QSqlQuery query;
    //bool ok1 = query.exec("create database user");
    //bool ok2 = query.exec("create table student(name varchar(10),age int,gender varchar(10))");
    //bool ok3 = query.exec("insert into student(name ,age ,gender) values('zhangsan',12,'男')");
    //qDebug()<<ok3;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL SERVER};SERVER=shj-pc;database=WebCS;uid=sa;pwd=123456");
    bool ok = db.open();
    qDebug()<<ok;
    QString table= "student";
    model->setTable(table);
    //将数据绑定到模型当中

    ui->tableView->setModel(model);
    //让model显示数据
    model->setTable("student");
    qDebug()<<model->lastError();

    QSqlQuery query;
    bool ok1 = query.exec("select * from student");
     qDebug()<<ok1;
    while(query.next())
    {
            qDebug()<<query.value(1).toString();
    }

    db.close();
}

Widget::~Widget()
{
    delete ui;
}
