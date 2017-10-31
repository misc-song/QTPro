#ifndef WIDGET_H
#define WIDGET_H
#include<QTimer>
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QTimer *time;
    int id;
    void timerEvent(QTimerEvent *event);
};

#endif // WIDGET_H
