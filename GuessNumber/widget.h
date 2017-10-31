#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTimer>
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
    void timerEvent(QTimerEvent *event);
    QTimer *gameTimer;
    void addNum();
private:
    int gameId ;//时间的ID
    QString inputVal;//保存输入的字符串
    int currentValue;//将当前输入的值转为int类型 保存在其中
    int rightValue;//保存随机数生成的值
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
