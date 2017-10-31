#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "userinfo.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
public:
    QVector<UserInfo> user;//用户列表



public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_openBtn_clicked();

    void on_createBtn_clicked();

    void on_saveBtn_clicked();


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
