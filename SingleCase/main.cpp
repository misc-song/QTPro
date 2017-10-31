#include <QCoreApplication>
#include<QDebug>
class MyConn
{
public:
    static void Open();
};

class MyClass
{

public:

    static MyClass *GetInvoke()
    {
        if(member==Q_NULLPTR)
        {
            member= new MyClass();
        }
        return member;
    }
private:
    static MyClass *member;
    MyClass()
    {
      ;
    }
public:
MyConn c;
public:
    ~MyClass();
};
MyClass *MyClass::member = Q_NULLPTR;

int main(int argc,char **argv)
{
    QCoreApplication a(argc, argv);
    qDebug()<<123;
    MyClass *s1 = MyClass::GetInvoke();
    MyClass *s2 = MyClass::GetInvoke();
    if(s1 == s2)
    {
        qDebug()<<"yes";
    }
    else
    {
        qDebug()<<"no";
    }
    s1->c.Open();
    return 0;

}
