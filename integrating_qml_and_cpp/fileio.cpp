#include "fileio.h"

FileIO::FileIO(QObject *parent): QObject(parent)
{

}

QString FileIO::readFile(const QString &source)
{\
    emit sourceChanged();
    QFile file;
    file.setFileName(source);
    if(file.open(QIODevice::ReadOnly))
    {
        return file.readAll();
    }

    return "error";
}

bool FileIO::writeFile(const QString &data)
{
    QString filepath = "../test.txt";
    QFile file;
    file.setFileName(filepath);
    if(file.open(QIODevice::WriteOnly))
    {
        file.write(data.toUtf8());
    }
    file.close();
    return true;
}
