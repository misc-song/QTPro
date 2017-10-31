#ifndef USERMODEL_H
#define USERMODEL_H
#include <QSqlDatabase>
#include<QSqlQuery>
#include <QObject>
#include<QDebug>
#include <QObject>
class UserModel:public QObject
{
    Q_OBJECT
public:
    UserModel();
    Q_INVOKABLE QString GetModel();
};

#endif // USERMODEL_H
