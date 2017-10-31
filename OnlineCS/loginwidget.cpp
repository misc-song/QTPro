#include "loginwidget.h"
#include "ui_loginwidget.h"
#include "mainpage.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
LogInWidget::LogInWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogInWidget)
{
    ui->setupUi(this);

    connect(ui->loginBtn,&QPushButton::clicked,this,
            [=]()
    {
        if(LogInWidget::checkLogin())
        {
            MainPage *mp = new MainPage();
            mp->show();
            this->hide();

        }
    });
    connect(ui->cancleBtn,&QPushButton::clicked,this,
            [=]()
    {
        this->close();
    }
    );
}

LogInWidget::~LogInWidget()
{
    delete ui;
}

bool LogInWidget::checkLogin( )
{
    QString username = ui->unameLineEdit->text();
    QString password = ui->UpwdLineEdit->text();
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QODBC");
    mydb.setDatabaseName("DRIVER={SQL SERVER};SERVER=shj-pc;database=webcs;uid=sa;pwd=123456");
    bool ok = mydb.open();
    qDebug()<<ok;
    QSqlQuery myquery;
    QString checkString = QString("select * from student where  sno= '%1' and sname='%2'").arg(username).arg(password);
    bool ko = myquery.exec(checkString);
    qDebug()<<ko;
    while(myquery.next())
    {
        qDebug()<<"success";
        mydb.close();
        return true;

    }
    qDebug()<<"false";
    mydb.close();
    return false;

}
