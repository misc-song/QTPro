#ifndef FILEIO_H
#define FILEIO_H
#include <QObject>
#include <QTextStream>
#include <QFile>

class FileIO:public QObject//只有QObject的子类才能被qml使用
{
    Q_OBJECT
public:
    //暴露给qml的接口
    Q_PROPERTY(QString source
               READ source
               WRITE setSource
               NOTIFY sourceChanged)
    explicit FileIO(QObject *parent = 0);

    Q_INVOKABLE QString read();
    Q_INVOKABLE bool write(const QString& data);

    QString source() { return mSource; }

public slots:
    void setSource(const QString& source) { mSource = source; }

signals:
    void sourceChanged(const QString& source);
    void error(const QString& msg);

private:
    QString mSource;
};

#endif // FILEIO_H
