#include "usermodel.h"

UserModel::UserModel()
{

}

QString UserModel::GetModel()
{
    //加载数据库驱动
    QSqlDatabase db =  QSqlDatabase::addDatabase("QSQLITE");
    //创建数据库文件
    db.setDatabaseName("user.db");
    bool y = db.open();
    qDebug()<<y;
    QSqlQuery query;//创建sql实例
    //创建一张用户表
    bool ok = query.exec("create table UserInfo(name int, age int,sex int)");
    //创建成功标志
    qDebug()<<ok;
    QSqlQuery query1;
    bool ok1 = query1.exec("insert into UserInfo(name,age,sex) values(1,2,3)");
    qDebug()<<ok1;
    //完成后关闭数据库
    db.close();
    QSqlQuery query3;
    query1.exec("select * form UserInfo");
    QString u;

    //    while(query3.next())
    //    {
    //        int i = 0;
    //        u("name:"+"%1,").arg(query3.value(i).toString());
    //    }
    qDebug()<<u;
    return u;
}
