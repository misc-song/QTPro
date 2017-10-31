#include "fileio.h"

FileIO::FileIO(QObject *parent)
{

}

void FileIO::openfile(QString filepath)
{
    filepath = filepath.remove(0,8);
    qDebug()<<filepath;
    QFile file(filepath);
//    file.open(QIODevice::ReadOnly);
//    QByteArray str = file.readAll();
//    text = str;
    if ( file.open(QIODevice::ReadOnly) ) {
            QString line;
            QTextStream t( &file );
            do {
                line = t.readLine();
                text += line;
             } while (!line.isNull());

            file.close();
        } else {
            text = "Unable to open the file";
        }
}

QString FileIO::showContext()
{
    return this->text;
}

void FileIO::savefile(QString filepath,QString filecontext)
{
    qDebug()<<filecontext;
    filepath = filepath.remove(0,8);
    qDebug()<<filepath;
    QFile file(filepath);
    if ( file.open(QIODevice::WriteOnly) ) {
            file.write(filecontext.toUtf8());
            file.close();
        } else {
            text = "Unable to open the file";
        }
}
