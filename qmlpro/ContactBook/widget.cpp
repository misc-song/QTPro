#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //获取支持的数据库
    qDebug()<<QSqlDatabase::drivers();
    //加载数据库驱动 采用SQLite数据库
    QSqlDatabase db =  QSqlDatabase::addDatabase("QSQLITE");

    //获取当前路径
    QDir dir(QDir::currentPath());

    //确认按钮
    OkBtn.setText("确认");
    OkBtn.setParent(this);
    OkBtn.setVisible(false);
    OkBtn.setGeometry(60,480,75,23);
    connect(&OkBtn,&QPushButton::clicked,this,Widget::onOKBtn);

    //取消按钮
    CancelBtn.setText("取消");
    CancelBtn.setParent(this);
    CancelBtn.setVisible(false);
    CancelBtn.setGeometry(230,480,75,23);
    connect(&CancelBtn,&QPushButton::clicked,this,Widget::onCancelBtn);

    //返回按钮
    ReturnBtn.setText("返回");
    ReturnBtn.setParent(this);
    ReturnBtn.setVisible(false);
    ReturnBtn.setGeometry(250,10,75,23);
    connect(&ReturnBtn,&QPushButton::clicked,this,Widget::onReturnBtn);


    //是否存在users.db这个文件
    bool isExist = dir.exists("users.db");
    if(!isExist)//不出在
    {
        //创建数据库文件
        db.setDatabaseName("users.db");
        //打开数据库
        bool y = db.open();
        qDebug()<<y;
        QSqlQuery query;//创建sql实例
        //创建一张用户表
        bool ok = query.exec("create table UserInfo(name nvarchar(20), moblieNum varchar(50),telNum varchar(50))");
        //创建成功标志
        qDebug()<<ok;
        //QSqlQuery query1;
        //创建种子文件
        bool ok1 = query.exec("insert into UserInfo(name,moblieNum,telNum) values('王五','13025401112','05535698256')");
        qDebug()<<ok1;
    }
    else{
        db.setDatabaseName("users.db");
        bool y = db.open();
        qDebug()<<y;

    }


    model = new QSqlTableModel(this);
    model->setTable("UserInfo");
    ui->tableView->setModel(model);
//    ui->tableView->setColumnWidth(0,100);
//    ui->tableView->setColumnWidth(1,160);
//    ui->tableView->setColumnWidth(2,160);
    model->select();


    model->setHeaderData(0,Qt::Horizontal,"姓名");
    model->setHeaderData(1,Qt::Horizontal,"手机号码");
    model->setHeaderData(2,Qt::Horizontal,"电话号码");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //完成后关闭数据库
    //db.close();

}

Widget::~Widget()
{
    delete ui;
}
//添加一个记录
//采用追加的方式
void Widget::on_AddBtn_clicked()
{
    QSqlRecord record = model->record();
    int row = model->rowCount();
    model->insertRecord(row,record);
    ui->AddBtn->setVisible(false);
    ui->DeleteBtn->setVisible(false);
    OkBtn.setVisible(true);
    CancelBtn.setVisible(true);
    //model->select();
    //model->submitAll();
}
//删除功能 可选中多行 一次性删除
void Widget::on_DeleteBtn_clicked()
{
    //获取选中的model
    QItemSelectionModel * selectModel = ui->tableView->selectionModel();
    //获取选中model的索引
    QModelIndexList list = selectModel->selectedRows();
    if(list.size() == 0)
    {
        QMessageBox::warning(this, tr("warning"), tr("请选择要删除的行"),
                             QMessageBox::Ok);
    }
    else
    {
        int ret = QMessageBox::warning(this, tr("warning"), tr("你真的要删除吗?"),
                                       QMessageBox::Ok|
                                       QMessageBox::Cancel);

        if(ret ==0x00000400)
        {
            //循环删除
            for(int i = 0; i<list.size();i++)
            {
                model->removeRow(list.at(i).row());
            }
        }
    }
    //    ui->DeleteBtn->setVisible(false);
    //    ui->AddBtn->setVisible(false);
    //    OkBtn.setVisible(true);
    //    CancelBtn.setVisible(true);
    model->submitAll();
    model->select();
}
//搜索功能
void Widget::on_SearchBtn_clicked()
{
    QString name = ui->SearchLEdit->text();
    QString str = QString("name = '%1'").arg(name);
    model->setFilter(str);
    model->select();
    ui->SearchBtn->setVisible(false);
    ReturnBtn.setVisible(true);
    ui->AddBtn->setVisible(false);
    ui->DeleteBtn->setVisible(false);
}

//回车搜索
void Widget::on_SearchLEdit_returnPressed()
{
    QString name = ui->SearchLEdit->text();
    QString str = QString("name = '%1'").arg(name);
    model->setFilter(str);
    model->select();
    ui->SearchBtn->setVisible(false);
    ReturnBtn.setVisible(true);
    ui->AddBtn->setVisible(false);
    ui->DeleteBtn->setVisible(false);
}

void Widget::on_Before_Insert()
{


}

void Widget::on_Before_Delete()
{

}

void Widget::onOKBtn()
{
    model->submitAll();
    OkBtn.setVisible(false);
    CancelBtn.setVisible(false);
    ui->AddBtn->setVisible(true);
    ui->DeleteBtn->setVisible(true);
}

void Widget::onCancelBtn()
{
    model->revertAll();
    model->submitAll();
    OkBtn.setVisible(false);
    CancelBtn.setVisible(false);
    ui->AddBtn->setVisible(true);
    ui->DeleteBtn->setVisible(true);

}

void Widget::onReturnBtn()
{
    model->setTable("UserInfo");
    ui->tableView->setModel(model);
//    ui->tableView->setColumnWidth(0,100);
//    ui->tableView->setColumnWidth(1,160);
//    ui->tableView->setColumnWidth(2,160);
    model->setHeaderData(0,Qt::Horizontal,"姓名");
    model->setHeaderData(1,Qt::Horizontal,"手机号码");
    model->setHeaderData(2,Qt::Horizontal,"电话号码");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    ReturnBtn.setVisible(false);
    ui->SearchBtn->setVisible(true);
    ui->AddBtn->setVisible(true);
    ui->DeleteBtn->setVisible(true);
}

void Widget::on_tableView_doubleClicked(const QModelIndex &index)
{
    ui->AddBtn->setVisible(false);
    ui->DeleteBtn->setVisible(false);
    CancelBtn.setVisible(true);
    OkBtn.setVisible(true);
}

void Widget::on_SearchLEdit_textChanged(const QString &arg1)
{

}
