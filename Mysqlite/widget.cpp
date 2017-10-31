#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //获取支持的数据库驱动
    qDebug()<<QSqlDatabase::drivers();
    //加载数据库驱动 采用SQLite数据库
    QSqlDatabase db =  QSqlDatabase::addDatabase("QSQLITE");
    //创建数据库文件
    db.setDatabaseName("user.db");
    bool y = db.open();
    qDebug()<<y;
    QSqlQuery query;//创建sql实例
    //创建一张用户表
    //bool ok = query.exec("create table UserInfo(name int, age int,sex int)");
    //创建成功标志
//    qDebug()<<ok;
//        QSqlQuery query1;
//        bool ok1 = query1.exec("insert into UserInfo(name,age,sex) values(1,2,3)");
//        qDebug()<<ok1;
    //完成后关闭数据库


    query.exec("select * from UserInfo");
    while(query.next())
    {

        qDebug()<<query.value(0).toString()+query.value(1).toString();
    }
     db.close();

}

Widget::~Widget()
{
    delete ui;
}
