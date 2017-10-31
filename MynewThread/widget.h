#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"mythread.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void dealSignal();
private slots:
    void on_startBtn_clicked();

    void on_stopBtn_clicked();

private:
    Ui::Widget *ui;
    Mythread *myT;
    QThread *thread;
};

#endif // WIDGET_H
