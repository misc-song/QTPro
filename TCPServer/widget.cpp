#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    tcpServer = NULL;//初始化tcpServer
    tcpServer = new QTcpServer(this);//实例化对象
    tcpServer->listen(QHostAddress::Any,8888);//构建连接端口
    connect(tcpServer,&QTcpServer::newConnection,//一旦连接成功将会触发newConnection 信号
            [=]()
    {
        tcpSocket = tcpServer->nextPendingConnection();//取出通信套接字
        QHostAddress  address =tcpSocket->peerAddress();//获取对方的地址
        quint16 port = tcpSocket->peerPort();//获取对方的端口
        QString temp = QString("成功链接至%1,%2").arg(address.toString()).arg(port);
        ui->textEditRead->append(temp);//将结果打印
        connect(tcpSocket,&QTcpSocket::readyRead,//读数据
                [=]()
        {
            QByteArray array = tcpSocket->readAll();//一次性读完
            ui->textEditRead->append(array);//追加到文本编辑框当中
        }
        );
    }
    );

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_SendBtn_clicked()//发送操作
{
    QString str = ui->textEditWrite->toPlainText();//获取文本
    tcpSocket->write(str.toUtf8().data());//将文本以字节数组的方式发送给客户端
}
