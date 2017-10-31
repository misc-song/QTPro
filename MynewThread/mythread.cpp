#include "mythread.h"

Mythread::Mythread(QObject *parent) : QObject(parent)
{

}

void Mythread::myTimeOut()
{
    while(1)
    {
        QThread::sleep(1);
        emit mySingal();
        qDebug()<<"主线程号"<<QThread::currentThread();
    }
}
