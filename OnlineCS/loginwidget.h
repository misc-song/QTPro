#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

namespace Ui {
class LogInWidget;
}

class LogInWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LogInWidget(QWidget *parent = 0);
    ~LogInWidget();
    bool checkLogin();
private:
    Ui::LogInWidget *ui;
};

#endif // LOGINWIDGET_H
