#include "widget.h"
#include "ui_widget.h"
//#include<QDebug>
#include<QHostAddress>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    tcpSocket = NULL;
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket,&QTcpSocket::connected,
            [=]()
    {
        ui->textEditRead->append("与服务器已经成功建立连接");
    }
    );
    connect(tcpSocket,&QTcpSocket::readyRead,//接受数据 当客户端给Server端发送数据的时候 自动触发readyRead信号
            [=]()
    {
        QByteArray array = tcpSocket->readAll();//一次读完所有的数据
        ui->textEditRead->append(array);//将数据追加到文本框中去

    }
    );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonConnect_clicked()//链接到服务器
{
    QString hostIp = ui->lineEditIP->text();//获取主机的IP
    quint16 port = ui->LineEditPort->text().toInt();//获取主机的端口号
    tcpSocket->connectToHost(QHostAddress(hostIp),port);//主动链接主机
}

void Widget::on_pushButtonSend_clicked()//发送操作
{
    QString str = ui->textEditWrite->toPlainText();//获取文本框的内容

    tcpSocket->write(str.toUtf8().data());//以字节数组的方式发送数据
}
