#include <QCoreApplication>
#include<thread>
#include<QDebug>
using namespace std;
void helloWord()
{
    qDebug()<<"helloWord"<<endl;
}
int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    std::thread t(helloWord);
    t.join();
    return a.exec();
}
