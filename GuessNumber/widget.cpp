#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QTime>
#include<QMessageBox>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //使用当前的时间作为种子 每次生成的结果都是不一样的
    qsrand( QTime(0,0,0).secsTo(QTime::currentTime()) );
    //循环取值保证数据是4位数
    while((rightValue = qrand()%10000)<999);
    qDebug()<<"rightValue is"<<rightValue;
    //设置当前的页面
    ui->stackedWidget->setCurrentWidget(ui->StartPage);
    //关联退出按钮的槽
    connect(ui->exitBtn,&QPushButton::clicked,this,&Widget::close);
    //关联开始游戏的槽
    connect(ui->startBtn,&QPushButton::clicked,this,
            //lamabda 表达式
            [=]() mutable
    {
        ui->stackedWidget->setCurrentWidget(ui->GamePage);//跳转至游戏页面
        gameTimer = new QTimer();//创建定时器
        gameId = this->startTimer(1000);//启动定时器

    }
    );
    //关联按钮的槽函数
    connect(ui->num0,&QPushButton::clicked,this,&Widget::addNum);
    connect(ui->num1,&QPushButton::clicked,this,&Widget::addNum);
    connect(ui->num2,&QPushButton::clicked,this,&Widget::addNum);
    connect(ui->num3,&QPushButton::clicked,this,&Widget::addNum);
    connect(ui->num4,&QPushButton::clicked,this,&Widget::addNum);
    connect(ui->num5,&QPushButton::clicked,this,&Widget::addNum);
    connect(ui->num6,&QPushButton::clicked,this,&Widget::addNum);
    connect(ui->num7,&QPushButton::clicked,this,&Widget::addNum);
    connect(ui->num8,&QPushButton::clicked,this,&Widget::addNum);
    connect(ui->num9,&QPushButton::clicked,this,&Widget::addNum);

    //关联textEdit文本内容发生改变时的槽函数
    connect(ui->textEdit,&QTextEdit::textChanged,this,\
            [=]()
    {
        QTextDocument *text = ui->textEdit->document();
        QString str = text->toRawText();
        if(str == '0')
        {
            ui->textEdit->clear();
        }
        if(str.length()>4)
        {
            QMessageBox::warning(this,"警告","不能大于四位数",QMessageBox::Yes);
            ui->textEdit->clear();
            inputVal.clear();
        }

        currentValue = str.toInt();

    }
    );
    connect(ui->okBtn,&QPushButton::clicked,this,
            [=]()
    {
        qDebug()<<"currentValue is"<<currentValue;
        if(rightValue > currentValue )
        {
            QMessageBox::warning(this,"warning","小了小了",QMessageBox::Yes);
            ui->textEdit->clear();
        }
        if(rightValue < currentValue )
        {
            QMessageBox::warning(this,"warning","大了大了",QMessageBox::Yes);
            ui->textEdit->clear();
        }
        if(rightValue == currentValue )
        {
            killTimer(gameId);
            QMessageBox::warning(this,"恭喜","回答正确",QMessageBox::Yes);
            ui->stackedWidget->setCurrentWidget(ui->SuccessPage);

        }
    }
    );
    connect(ui->cancleBtn,&QPushButton::clicked,this,
            [=]()
    {
        ui->stackedWidget->setCurrentWidget(ui->FailPage);
    }
    );

}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == gameId)//根据定时器的id来选择对应的操作（过滤定时器事件）
    {
        QString str =ui->timeBox->currentText();

        double static processRemain = str.toDouble();
        double static num = 100;
        double static remain = 100;
        remain = remain-(num/processRemain);
        ui->timerProc->setValue(remain);
        //qDebug()<<remain;
        if(0 == remain)
        {
            killTimer(gameId);
            ui->stackedWidget->setCurrentWidget(ui->FailPage);
        }
    }

}

void Widget::addNum()
{
    QPushButton *pt = qobject_cast<QPushButton *>(sender());
    if(pt == ui->num0)
    {
        inputVal.append("0");
        ui->textEdit->setText(inputVal);
    }
    else if(pt == ui->num1)
    {
        inputVal.append("1");
        ui->textEdit->setText(inputVal);
    }
    else if(pt == ui->num2)
    {
        inputVal.append("2");
        ui->textEdit->setText(inputVal);
    }
    else if(pt == ui->num3)
    {
        inputVal.append("3");
        ui->textEdit->setText(inputVal);
    }
    else if(pt == ui->num4)
    {
        inputVal.append("4");
        ui->textEdit->setText(inputVal);
    }
    else if(pt == ui->num5)
    {
        inputVal.append("5");
        ui->textEdit->setText(inputVal);
    }
    else if(pt == ui->num6)
    {
        inputVal.append("6");
        ui->textEdit->setText(inputVal);
    }
    else if(pt == ui->num7)
    {
        inputVal.append("7");
        ui->textEdit->setText(inputVal);
    }
    else if(pt == ui->num8)
    {
        inputVal.append("8");
        ui->textEdit->setText(inputVal);
    }
    else if(pt == ui->num9)
    {
        inputVal.append("9");
        ui->textEdit->setText(inputVal);
    }
    else
        return;


}


