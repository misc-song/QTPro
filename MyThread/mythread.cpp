#include "mythread.h"

Mythread::Mythread(QObject *parent) : QThread(parent)
{

}

void Mythread::run()
{
    QThread::sleep(5);
    emit dealRunOK();

}
