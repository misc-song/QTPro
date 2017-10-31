#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL SERVER};SERVER=shj-pc;database=webcs;uid=sa;pwd=123456");
    bool ok = db.open();
    qDebug()<<ok;
    model->setTable("Student");
    model->select();
    ui->tableView->setModel(model);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    model->setTable("student");
    model->select();
    ui->tableView->setModel(model);
}
