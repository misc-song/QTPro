#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_clearBtn_clicked();

    void on_sendBtn_clicked();

    void on_linkBtn_clicked();
    void Read_Data();
private:
    Ui::Widget *ui;
    QSerialPort *serial;
};

#endif // WIDGET_H
