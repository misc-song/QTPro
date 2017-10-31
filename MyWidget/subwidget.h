#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include<QPushButton>
class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);
    QPushButton btn;
    void SubToMian();
signals:
    void EmitS();
public slots:
};

#endif // SUBWIDGET_H
