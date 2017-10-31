#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    {
        int number = 0;
        qDebug()<<&number;
    }
    {
        int number = 1;
         qDebug()<<&number;
    }
    {
        int number = 2;
         qDebug()<<&number;
    }
    {
        int number = 3;
         qDebug()<<&number;
    }
    {
        int number = 4;
         qDebug()<<&number;
    }

    /*****************************Qt连接mysql数据库 在不指定连接名的情况下*********************************/
    //    qDebug()<< QSqlDatabase::drivers();
    //    QSqlDatabase db =  QSqlDatabase::addDatabase("QMYSQL");
    //    db.setHostName("localhost");
    //    db.setUserName("root");
    //    db.setPassword("123456");
    //    db.setDatabaseName("users");
    //    bool ok = db.open();
    //    if(ok==true)
    //    {
    //        qDebug()<<"connect sucsess!"<<endl;
    //    }
    //    else
    //    {
    //        qDebug()<<"connect faild!"<<endl;
    //        qDebug()<<db.lastError()<<endl;
    //    }
    //    QSqlQuery query;
    //    bool ok1 = query.exec("create table mytable(myname varchar(50),mysex varchar(50));");
    //    if(ok1==true)
    //    {
    //        qDebug()<<"query ok!"<<endl;
    //    }
    //    else
    //    {
    //        qDebug()<<"connect faild!"<<endl;
    //        qDebug()<<db.lastError()<<endl;
    //    }


    /*****************************Qt连接mysql数据库 在指定连接名的情况下*********************************/
    //    QSqlDatabase db1 =  QSqlDatabase::addDatabase("QMYSQL","a");
    //    db1.setHostName("localhost");
    //    db1.setUserName("root");
    //    db1.setPassword("123456");
    //    db1.setDatabaseName("users");
    //    bool ok = db1.open();
    //    if(ok==true)
    //    {
    //        qDebug()<<"connect sucsess!"<<endl;
    //    }
    //    else
    //    {
    //        qDebug()<<"connect faild!"<<endl;
    //        qDebug()<<db1.lastError()<<endl;
    //    }
    //    QSqlQuery query1(db1);
    //    bool ok1 = query1.exec("create table mynewtable(myname varchar(50),mysex varchar(50));");
    //    if(ok1==true)
    //    {
    //        qDebug()<<"query ok!"<<endl;
    //    }
    //    else
    //    {
    //        qDebug()<<"connect faild!"<<endl;
    //        qDebug()<<db1.lastError()<<endl;
    //    }

    /*****************************Qt连接sqlserver数据库*********************************/
    //    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    //    db.setDatabaseName(QString("DRIVER={SQL SERVER};"
    //                               "SERVER=%1;"
    //                               "DATABASE=%2;"
    //                               "UID=%3;"
    //                               "PWD=%4;").arg("SHJ-PC")
    //                       .arg("BookStore")
    //                       .arg("sa")
    //                       .arg("123456"));
    //    bool ok = db.open();
    //    if (ok)
    //    {
    //        qDebug()<<"Connect to Database Success!";
    //        //        QMessageBox::warning(0, qApp->tr("Cannot open database"),
    //        //        db.lastError().databaseText(), QMessageBox::Cancel);
    //    }
    //    else
    //    {
    //        qDebug()<<"Connect to Database faild!";
    //    }
    //    QSqlQuery query;
    //    query.exec("create table mynewtable(myname varchar(50),mysex varchar(50));");

}

Widget::~Widget()
{
    delete ui;
}
