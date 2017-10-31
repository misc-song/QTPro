#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    myserver = new QTcpServer(this);
    myserver->listen(QHostAddress::Any,8888);
    connect(myserver,&QTcpServer::newConnection,
            [=]()
    {
        mysocket = myserver->nextPendingConnection();
        QHostAddress address = mysocket->peerAddress();
        quint16 port = mysocket->peerPort();
        QString peerInfo = QString("[%1,%2]:成功链接至服务器").arg(address.toString()).arg(port);
        ui->textEditRead->setText(peerInfo);
        connect(mysocket,&QTcpSocket::readyRead,
                [=]()
        {
            if(mysocket == NULL)
            {
                ui->textEditRead->append("链接尚未就绪...找不到目标主机");
            }
            else
            {
                QString temp = mysocket->readAll();
                ui->textEditRead->append(temp);
            }
        }
        );
        connect(mysocket,&QTcpSocket::disconnected,
                [=]()
        {
            ui->textEditRead->append("通信结束");
        }

        );
    }
    );

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_sendBtn_clicked()
{
    QString str = ui->textEditWrite->toPlainText();
    mysocket->write(str.toUtf8().data());
}

void Widget::on_closeBtn_clicked()
{
    if(mysocket==NULL)
    {
        ui->textEditRead->append("无连接。。。");
    }
    else
    {
        mysocket->close();
        mysocket =NULL;
        ui->textEditRead->append("已成功关闭连接");
    }

}
