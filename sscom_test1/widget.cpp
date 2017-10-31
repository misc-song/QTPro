#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
    //查找可用串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            ui->port->addItem(serial.portName());
            serial.close();
        }
    }
    ui->sendBtn->setEnabled(false);
    ui->reciveArea->setReadOnly(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_clearBtn_clicked()
{
    ui->reciveArea->clear();
    ui->sendArea->clear();
}

void Widget::on_sendBtn_clicked()
{
    serial->write(ui->sendArea->toPlainText().toLatin1());
}

void Widget::on_linkBtn_clicked()
{
    if(ui->linkBtn->text()==tr("连接"))
    {
        serial = new QSerialPort;
        //设置串口名
        serial->setPortName(ui->port->currentText());
        //打开串口
        serial->open(QIODevice::ReadWrite);
        //设置波特率
        serial->setBaudRate(ui->boundlevel->currentText().toInt());
        //设置数据位数
        switch(ui->databit->currentIndex())
        {
        case 8: serial->setDataBits(QSerialPort::Data8); break;
        default: break;
        }
        //设置奇偶校验
        switch(ui->checkbit->currentIndex())
        {
        case 0: serial->setParity(QSerialPort::NoParity); break;
        default: break;
        }
        //设置停止位
        switch(ui->stopbit->currentIndex())
        {
        case 1: serial->setStopBits(QSerialPort::OneStop); break;
        case 2: serial->setStopBits(QSerialPort::TwoStop); break;
        default: break;
        }
        //设置流控制
        serial->setFlowControl(QSerialPort::NoFlowControl);
        //关闭设置菜单使能
        ui->port->setEnabled(false);
        ui->boundlevel->setEnabled(false);
        ui->databit->setEnabled(false);
        ui->checkbit->setEnabled(false);
        ui->stopbit->setEnabled(false);
        ui->linkBtn->setText(tr("关闭串口"));
        ui->sendBtn->setEnabled(true);
        //连接信号槽
        QObject::connect(serial, &QSerialPort::readyRead, this, &Widget::Read_Data);
    }
    else
    {
        //关闭串口
        serial->clear();
        serial->close();
        serial->deleteLater();
        //恢复设置使能
        ui->port->setEnabled(true);
        ui->boundlevel->setEnabled(true);
        ui->databit->setEnabled(true);
        ui->checkbit->setEnabled(true);
        ui->stopbit->setEnabled(true);
        ui->linkBtn->setText(tr("打开串口"));
        ui->sendBtn->setEnabled(false);
    }
}
void Widget::Read_Data()
{
    QByteArray buf;
    buf = serial->readAll();
    if(!buf.isEmpty())
    {
        QString str = ui->reciveArea->toPlainText();
        str+=tr(buf);
        ui->reciveArea->clear();
        ui->reciveArea->append(str);
    }
    buf.clear();
}
