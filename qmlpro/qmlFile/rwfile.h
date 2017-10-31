#ifndef RWFILE_H
#define RWFILE_H
#include<QObject>
#include<QFile>
class RWFile:public QObject
{
    Q_OBJECT
    //Q_PROPERTY(string filepath READ filepath WRITE setFilepath NOTIFY filepathChanged)

public:
    RWFile(QObject *parent = 0);

    QString text;
public:
    Q_INVOKABLE void openfile(QString filepath);
    Q_INVOKABLE QString showContext();

};

#endif // RWFILE_H
