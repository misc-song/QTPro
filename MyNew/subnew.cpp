#include "subnew.h"

SubNew::SubNew(QWidget *parent) : QWidget(parent)
{
    btn.setText("gotomain");
    btn.setParent(this);
    connect(&btn,&QPushButton::pressed,this,
            [=]()
    {
        emit EmitS();
    }
    );
}
