#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mysocket = NULL;
    mysocket = new QTcpSocket(this);
    connect(mysocket,&QTcpSocket::connected,
            [=]()
    {
        ui->textEditRead->setText("成功链接至服务器");
    }
    );
    connect(mysocket,&QTcpSocket::readyRead,
            [=]()
    {
        QString tmp = mysocket->readAll();
        ui->textEditRead->append(tmp);
    }
    );
    connect(mysocket,&QTcpSocket::disconnected,
            [=]()
    {

        ui->textEditRead->append("通信结束");
    }
    );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_connectBtn_clicked()
{

    QString ip = ui->lineEditIP->text();
    quint16 port = ui->lineEditPort->text().toInt();
    mysocket->connectToHost(ip,port);
}

void Widget::on_closeBtn_clicked()
{
    if(mysocket == NULL)
    {
        ui->textEditRead->append("当前无连接。。。");
    }
    else
    {
        mysocket->close();
        //mysocket = NULL;
    }
}

void Widget::on_sendBtn_clicked()
{
    if(mysocket == NULL)
    {
        ui->textEditRead->append("当前无连接。。。");
    }
    else
    {
        QString temp = ui->textEditWrite->toPlainText();
        mysocket->write(temp.toUtf8().data());
    }

}
