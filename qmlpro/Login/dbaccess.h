#ifndef DBACCESS_H
#define DBACCESS_H
#include "userinfo.h"
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QDir>
class DBAccess:public QObject
{
    Q_OBJECT
public:
    DBAccess(QObject *parent = 0);
    Q_INVOKABLE bool CreateDB();
    Q_INVOKABLE bool GetModel(QString username,QString userpwd);
    Q_INVOKABLE bool InsertModel(QString username,QString userpwd);
public:

    QSqlDatabase db;

};

#endif // DBACCESS_H
