#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class Mythread : public QThread
{
    Q_OBJECT
public:
    explicit Mythread(QObject *parent = nullptr);
    void run();
signals:
    void dealRunOK();
public slots:
};

#endif // MYTHREAD_H
