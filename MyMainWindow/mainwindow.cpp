#include "mainwindow.h"
#include<QMenuBar>
#include<QMenu>
#include<QDebug>
#include<QToolBar>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *mBar = menuBar();
    QMenu *pFile = mBar->addMenu("文件");
    QAction *pNew = pFile->addAction("新建");
    pFile->addSeparator();
    connect(pNew,&QAction::triggered,
            [=]()
            {
                qDebug()<<"新建按钮被点下";
            }
    );
     QAction *pOpen = pFile->addAction("打开");
     QToolBar *toolBar = addToolBar("toolbar");
     toolBar->addAction(pOpen);
}

MainWindow::~MainWindow()
{

}
