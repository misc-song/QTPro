#ifndef WIDGET_H
#define WIDGET_H
#include"subwidget.h"
#include <QWidget>
#include<QPushButton>
class Widget : public QWidget
{
    Q_OBJECT
private:
    QPushButton btn;
    SubWidget sub;
    void GotoSub();
    void RetuenMain();
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
