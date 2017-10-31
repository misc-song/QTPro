#include "widget.h"
#include "ui_widget.h"
#include<QFileDialog>
#include<QDebug>
#include<QTextStream>
#include<QStringList>
#include"userinfo.h"
#include<time.h>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

//随机方法
int random(int ra)
{
    srand((unsigned)time(NULL));
    int num = (rand() % (ra-0))+ 0;
    return num;
}

template<typename T>
void WriteFile(T myobj)
{

    if(myobj.size()<10)
    {
        qDebug()<<myobj.size();
        for(int x = 0;x<myobj.size();x++)
        {
            qDebug()<<myobj.at(x).Dept<<myobj.at(x).UCon<<myobj.at(x).Uname<<myobj.at(x).Usex;
        }
        return;
    }
    else
    {
        int totalCount = myobj.size();//总的记录数
        int ArrayCount = totalCount/10;//组数
        QVector<QVector<UserInfo>> temp(ArrayCount);
        QVector<UserInfo> female;//存储男生
        QVector<UserInfo> male;//存储女生
        for(int i = 0;i<myobj.size();i++)
        {
            if(myobj.at(i).Usex=="女")
            {
                female.append(myobj.at(i));
            }
            else if(myobj.at(i).Usex=="男")
            {
                male.append(myobj.at(i));
            }
        }
        int maleCount = male.size();
        int femaleCount = female.size();
        int maleArray = male.size()/ArrayCount;//每组中男生的个数
        int maleArrayRemain = male.size()%ArrayCount;//男生剩余个数
        int femaleArray = female.size()/ArrayCount;//每组中女生的个数
        int femaleArrayRemain = female.size()%ArrayCount;//女生剩余个数
        for(int mf = 0; mf<ArrayCount;mf++)
        {
            for(int m = 0;m<maleArray;m++)
            {
                //随机添加男
                //temp[mf].append(male.at(m));
                int randNumMale =  random(maleCount);
                temp[mf].append(male.at(randNumMale));
                male.erase(male.begin()+randNumMale);
                maleCount--;
            }
            for(int f = 0;f<femaleArray;f++)
            {
                //随机添加女
                //temp[mf].append(fmale.at(f));
                int randNumFemale =  random(femaleCount);
                temp[mf].append(female.at(randNumFemale));
                female.erase(female.begin()+randNumFemale);
                femaleCount--;
            }
            if(maleArrayRemain>0)
            {
                int randNumMale =  random(maleArrayRemain);
                temp[mf].append(male.at(randNumMale));
                male.erase(male.begin()+randNumMale);
                maleArrayRemain--;
                maleCount--;
            }
            else if(femaleArrayRemain>0)
            {
                int randNumMale =  random(femaleArrayRemain);
                temp[mf].append(female.at(randNumMale));
                female.erase(female.begin()+randNumMale);
                femaleArrayRemain--;
                femaleCount--;
            }
            else
            {

            }

        }


        for(int ma=0;ma<temp.size();ma++)
        {
            // qDebug()<<(temp.at(ma)).length();
            // qDebug()<<temp.begin()->length();
            qDebug()<<temp[ma].size();
            for(int mb=0;mb<(temp.at(ma)).size();mb++)
            {
                qDebug()<<temp[ma].at(mb).Dept<<temp[ma].at(mb).UCon<<temp[ma].at(mb).Uname<<temp[ma].at(mb).Usex;
                //qDebug()<<"ooooo";
            }
            //qDebug()<<"lalala";
        }


    }
}
template<typename T>
void WriteFile2(T myobj)
{



    int totalCount = myobj.size();//总的记录数
    int ArrayCount = totalCount/10;//组数
    QVector<QVector<UserInfo>> temp(ArrayCount+1);
    QVector<UserInfo> female;//存储男生
    QVector<UserInfo> male;//存储女生
    for(int i = 0;i<myobj.size();i++)
    {
        if(myobj.at(i).Usex=="女")
        {
            female.append(myobj.at(i));
        }
        else if(myobj.at(i).Usex=="男")
        {
            male.append(myobj.at(i));
        }
    }
    int maleCount = male.size();
    int femaleCount = female.size();
    int maleArray = male.size()/ArrayCount;//每组中男生的个数
    int maleArrayRemain = male.size()%ArrayCount;//男生剩余个数
    int femaleArray = female.size()/ArrayCount;//每组中女生的个数
    int femaleArrayRemain = female.size()%ArrayCount;//女生剩余个数
    int mf;
    for(mf = 0; mf<ArrayCount;mf++)
    {
        for(int f = 0;f<femaleArray;f++)
        {
            //随机添加女
            //temp[mf].append(fmale.at(f));
            int randNumFemale =  random(femaleCount);
            temp[mf].append(female.at(randNumFemale));
            female.erase(female.begin()+randNumFemale);
            femaleCount--;
        }
        for(int m = 0;m<maleArray;m++)
        {
            //随机添加男
            //temp[mf].append(male.at(m));
            int randNumMale =  random(maleCount);
            temp[mf].append(male.at(randNumMale));
            male.erase(male.begin()+randNumMale);
            maleCount--;
        }

    }
    if(mf==ArrayCount)
    {
        for(int mr=0;mr<(maleArrayRemain);)
        {
            if(maleArrayRemain>0)
            {
                int randNumMale =  random(maleArrayRemain);
                temp[mf].append(male.at(randNumMale));
                male.erase(male.begin()+randNumMale);
                maleArrayRemain--;
                // maleCount--;
            }

        }
        for(int mr=0;mr<(femaleArrayRemain);)
        {
            if(femaleArrayRemain>0)
            {
                int randNumMale =  random(femaleArrayRemain);
                temp[mf].append(female.at(randNumMale));
                female.erase(female.begin()+randNumMale);
                femaleArrayRemain--;
                // femaleCount--;
            }
        }

    }
    for(int ma=0;ma<temp.size();ma++)
    {
        // qDebug()<<(temp.at(ma)).length();
        // qDebug()<<temp.begin()->length();
        qDebug()<<temp[ma].size();
        for(int mb=0;mb<(temp.at(ma)).size();mb++)
        {
            qDebug()<<temp[ma].at(mb).Dept<<temp[ma].at(mb).UCon<<temp[ma].at(mb).Uname<<temp[ma].at(mb).Usex;
            //qDebug()<<"ooooo";
        }
        //qDebug()<<"lalala";
    }



}





template<typename T>
void WriteFile3(T myobj)
{





}

void Widget::on_pushButton_clicked()
{
    QFileDialog* fd = new QFileDialog(this);//创建打开文件对话框
    QString fileName = fd->getOpenFileName(this,tr("Open File"),"/home",tr("Excel(*.csv)"));
    if(fileName == "")
        return;
    QDir dir = QDir::current();
    QFile file(dir.filePath(fileName));
    if(!file.open(QIODevice::ReadOnly))
        qDebug()<<"OPEN FILE FAILED";
    QTextStream * out = new QTextStream(&file);//文本流
    QStringList tempOption = out->readAll().split("\n");//每行以\n区分
    tempOption.pop_back();
    QVector<UserInfo> users;
    for(int i = 3 ; i < tempOption.count() ; i++)
    {
        QStringList tempbar = tempOption.at(i).split(",");//一行中的单元格以，区分
        //...//省略具体对数据的操作
        UserInfo tempuser;
        for(int j = 0;j<tempbar.size();j++)
        {
            bool ok;
            tempbar[j].toInt(&ok,10);
            if(ok)
            {
                continue;
            }
            if(tempbar[j]=="")
            {
                continue;
            }
            else
            {

                tempuser.Dept = tempbar[j].trimmed();
                tempuser.Uname = tempbar[j+1].trimmed();
                tempuser.Usex = tempbar[j+2].trimmed();
                tempuser.UCon = tempbar[j+3].trimmed();
                break;
            }
            //ui->textEdit->append(tempbar[j]);
        }
        users.append(tempuser);
    }
    qDebug()<<users.size();


    if(file.isOpen())
    {
        file.close();//操作完成后记得关闭文件
    }

}
