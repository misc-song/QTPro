#include "rwfile.h"
#include<QTextStream>
#include<QDebug>
RWFile::RWFile(QObject *parent)
{

}

void RWFile::openfile(QString filepath)
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

QString RWFile::showContext()
{
//    if(this->text == "")
//    {
//        return "hello";
//    }
//    else
//    {
        return this->text;
//    }
}
