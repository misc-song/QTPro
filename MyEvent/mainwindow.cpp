#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QSlider>
#include<QSpinBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider,&QSlider::valueChanged,
            [=]()
    {
        int i = ui->horizontalSlider->value();
        ui->spinBox->setValue(i);
    }
    );
    connect(ui->spinBox,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            [=]()
    {
        int j = ui->spinBox->value();
        ui->horizontalSlider->setValue(j);
    }
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}
