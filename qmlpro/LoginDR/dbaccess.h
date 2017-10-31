#ifndef DBACCESS_H
#define DBACCESS_H
#include "userinfo.h"
#include <QObject>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDir>
#include<QDebug>
class DBAccess:public QObject
{
    Q_OBJECT
public:
    DBAccess();
    Q_INVOKABLE bool CreateDB();
    Q_INVOKABLE bool GetModel(QString username,QString userpwd);
    Q_INVOKABLE bool GetModelByName(QString username);
    Q_INVOKABLE bool InsertModel(QString username,QString userpwd);

    QSqlDatabase db;
};

#endif // DBACCESS_H
