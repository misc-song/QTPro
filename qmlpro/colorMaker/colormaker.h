#ifndef COLORMAKER_H
#define COLORMAKER_H
#include<QObject>
#include<QDateTime>
#include<QColor>
#include<QTimerEvent>
//将C++中的类在qml中使用 类必须继承自QObject
class ColorMaker:public QObject
{
    Q_OBJECT
    Q_ENUMS(GenerateAlgorithm)
    //Q_PROPERTY用来定义可通过元对象来访问的属性 通过//Q_PROPERTY来定义的属性在可以再qml中访问修改
    //Q_PROPERTY宏是QOBJECT宏的后裔 所以使用Q_PROPERTY宏之前必须先使用Q_OBJECT宏
    //READ标记 生明一个可读属性
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QColor timeColor READ timeColor)
public:
    ColorMaker(QObject *parent = 0);
    ~ColorMaker();

    enum GenerateAlgorithm{
        RandomRGB,
        RandomRed,
        RandomGreen,
        RandomBlue,
        LinearIncrease
    };
    QColor color() const;
    void setColor(const QColor &color);
    QColor timeColor() const;
    Q_INVOKABLE GenerateAlgorithm algorithm() const;//使用Q_INVOKABLE宏来修饰 可以让方法被元对象系统调用
    Q_INVOKABLE void setAlgorithm (GenerateAlgorithm algorithm);
signals:
    void colorChanged(const QColor &color);
    void currentTime(const QString &strTime);
public slots:
    void start();
    void stop();
protected:
    void timerEvent(QTimerEvent *e);
private:
    GenerateAlgorithm m_algorithm;
    QColor m_currentColor;
    int m_nColorTimer;
};

#endif // COLORMAKER_H
