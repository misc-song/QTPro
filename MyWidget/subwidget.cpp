#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    btn.setText("go to main");
    btn.setParent(this);
    connect(&btn,&QPushButton::pressed,this,&SubWidget::SubToMian);
}

void SubWidget::SubToMian()
{
    emit EmitS();
}
