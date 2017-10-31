#ifndef MYTHREAD_H
#define MYTHREAD_H
#include<QDebug>
#include <QObject>
#include<QThread>
class Mythread : public QObject
{
    Q_OBJECT
public:
    explicit Mythread(QObject *parent = nullptr);

    void myTimeOut();

signals:
    void mySingal();
public slots:
};

#endif // MYTHREAD_H
