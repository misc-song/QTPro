#ifndef FILEIO_H
#define FILEIO_H
#include<QObject>
#include<QFile>
#include<QTextStream>
#include<QDebug>

class FileIO:public QObject
{
     Q_OBJECT
public:

    FileIO(QObject *parent = 0);

    QString text;
public:
    Q_INVOKABLE void openfile(QString filepath);
    Q_INVOKABLE QString showContext();
    Q_INVOKABLE void savefile(QString filepath,QString filecontext);
};

#endif // FILEIO_H
