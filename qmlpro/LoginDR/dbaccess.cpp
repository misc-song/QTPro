#include "dbaccess.h"

DBAccess::DBAccess()
{

}

bool DBAccess::CreateDB()
{
    QDir dir(QDir::currentPath());
    bool isExist = dir.exists("user.db");
    if(!isExist)
    {
        //qDebug()<<QSqlDatabase::drivers();
        //加载数据库驱动 采用SQLite数据库
        db =  QSqlDatabase::addDatabase("QSQLITE");
        //创建数据库文件
        db.setDatabaseName("user.db");
        db.open();
        QSqlQuery query;//创建sql实例
        //创建一张用户表
        bool ok = query.exec("create table UserInfo(username varchar(50), userpwd varchar(50))");
        //创建成功标志
        qDebug()<<ok;
        db.close();
        return true;
    }
    else
    {
        db =  QSqlDatabase::addDatabase("QSQLITE");
        return true;
    }
}

bool DBAccess::GetModel(QString username, QString userpwd)
{
    db.setDatabaseName("user.db");
    db.open();
    QSqlQuery query;
    query.exec(QString("select * from userinfo where username = '%1' and userpwd = '%2'").arg(username).arg(userpwd));
    if(query.next())
    {
        db.close();
        return true;
    }
    else
    {
        db.close();
        return false;
    }

}

bool DBAccess::GetModelByName(QString username)
{
    db.setDatabaseName("user.db");
    db.open();
    QSqlQuery query;
    query.exec(QString("select * from userinfo where username = '%1'").arg(username));
    if(query.next())
    {
        db.close();
        return true;
    }
    else
    {
        db.close();
        return false;
    }
}

bool DBAccess::InsertModel(QString username, QString userpwd)
{
    db.setDatabaseName("user.db");
    db.open();
    QSqlQuery query;
    bool ok =query.exec(QString("insert into userinfo(username,userpwd) values('%1','%2')").arg(username).arg(userpwd));
    if(ok)
    {
        db.close();
        return true;
    }
    else
    {
        db.close();
        return false;
    }

}
