#ifndef SUBNEW_H
#define SUBNEW_H

#include <QWidget>
#include<QPushButton>
class SubNew : public QWidget
{
    Q_OBJECT
public:
    explicit SubNew(QWidget *parent = nullptr);
    QPushButton btn;

signals:
    void EmitS();
public slots:
};

#endif // SUBNEW_H
