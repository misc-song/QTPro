#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTcpServer>
#include<QTcpSocket>
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
    void on_sendBtn_clicked();

    void on_closeBtn_clicked();

private:
    Ui::Widget *ui;
    QTcpServer *myserver;
    QTcpSocket *mysocket;
};

#endif // WIDGET_H
