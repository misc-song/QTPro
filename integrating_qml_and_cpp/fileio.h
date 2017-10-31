#ifndef FILEIO_H
#define FILEIO_H
#include<QFile>
#include<QObject>
#include <QTextStream>
#include <QDebug>
class FileIO:public QObject
{
    Q_OBJECT
     Q_PROPERTY(QString source READ source WRITE setSource NOTIFY sourceChanged)
public:

    explicit FileIO(QObject *parent = 0);

    Q_INVOKABLE QString readFile(const QString &source);

    Q_INVOKABLE bool writeFile(const QString& data);

    QString source() { return mSource; }
private :
    QString mSource;
};

#endif // FILEIO_H
