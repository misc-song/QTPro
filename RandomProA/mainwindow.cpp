#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QDebug>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
random(int ra)
{
    srand((unsigned)time(NULL));
    int num = (rand() % (ra-0))+ 0;
    return num;
}
void MainWindow::on_action_O_triggered()
{
    QFileDialog* fd = new QFileDialog(this);
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

    for(int i = 0 ; i < tempOption.count() ; i++)
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
    for(int i = 0; i < users.size();i++)
    {
        ui->textBrowser->append(users[i].Dept+users[i].UCon+users[i].Uname+users[i].Usex);
        if(users[i].Usex == "男")
        {
            male.append(users[i]);
        }
        else
        {
            female.append(users[i]);
        }
    }
    maleCount = male.size();
    femaleCount = female.size();
    female.size();
    cmaleNum = maleCount/classNum;
    cfemaleNum = femaleCount/classNum;
    maleRemain = maleCount%classNum;
    femaleRemain = femaleCount%classNum;
    QString total = QString::number(users.size());
    ui->totalLab->setText(total+"条");
    qDebug()<<"总的记录数"<<users.size()<<"男生的个数"<<maleCount<<"女生的个数"<<femaleCount<<"每组男生的个数"<<cmaleNum<<"每组女生的个数"<<cfemaleNum<<"男生剩余的个数"<<maleRemain<<"女生剩余的个数"<<femaleRemain;
}

void MainWindow::on_pushButton_clicked()
{

    QVector<UserInfo> tempUser;
    //从男生组中选人
    if(maleCount == 0&&femaleCount==0)
    {
        QMessageBox::warning(this,tr("提示"),tr("分组已经完成"),QMessageBox::Ok);
        return ;
    }
    ui->classCount->setText("第"+QString::number(CountBtn)+"组");
    for(int ma=0;ma<cmaleNum;ma++)
    {
        int randNumFemale = random(maleCount);
        tempUser.append(male[randNumFemale]);
        male.erase(male.begin()+randNumFemale);
        maleCount--;
    }
    //从女生组中选人
    for(int ma = 0; ma<cfemaleNum;ma++)
    {
        int randNumFemale = random(femaleCount);
        tempUser.append(female[randNumFemale]);
        female.erase(female.begin()+randNumFemale);
        femaleCount--;
    }
    int tempNum =random(1);

    if(tempNum<1&&(maleRemain!=0))
    {
        int randNumFemale = random(maleCount);
        tempUser.append(male[randNumFemale]);
        male.erase(male.begin()+randNumFemale);
        maleCount--;
        maleRemain--;
    }
    else if(femaleRemain!=0)
    {

        int randNumFemale = random(femaleRemain);
        tempUser.append(female[randNumFemale]);
        female.erase(female.begin()+randNumFemale);
        femaleCount--;
        femaleRemain--;

    }
    else
    {

    }
    CountBtn++;
    qDebug()<<tempUser.size();
    ui->textEdit->clear();
    for(int hh=0;hh<tempUser.size();hh++)
    {

        ui->textEdit->append(tempUser[hh].Dept+","+tempUser[hh].UCon+","+tempUser[hh].Uname+","+tempUser[hh].Usex);
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    QFileDialog* fd = new QFileDialog(this);
    QString fileName = "/home/组"+QString::number(CountBtn-1);
    fileName = fd->getSaveFileName(this,tr("Save File"),fileName,tr("Excel(*.csv)"));
    if(fileName == "")
    {
        QMessageBox::warning(this,tr("警告"),tr("点击保存，保存文件"),QMessageBox::Ok);
    }
    QDir dir = QDir::current();
    QFile file(dir.filePath(fileName));
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Open failed." << endl;
        return ;
    }
    QTextStream txtOutput(&file);
    txtOutput<<ui->textEdit->toPlainText();
    file.close();
}

void MainWindow::on_action_V_triggered()
{
    QMessageBox::aboutQt(this,"beta1.2");
    //power by shj;
}

void MainWindow::on_action_H_triggered()
{
    QMessageBox::about(this,"呵呵，没有！","帮助？不存在的！");
}

void MainWindow::on_action_X_triggered()
{
    this->close();
}
