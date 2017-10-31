#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPushButton>
#include"subnew.h"
class Widget : public QWidget
{
    Q_OBJECT
public:
    QPushButton btn;
    SubNew sub;

public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
