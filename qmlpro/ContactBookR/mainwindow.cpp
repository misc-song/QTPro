#include "mainwindow.h"

void MainWindow::onOkbtnClicked()
{
    model->submitAll();
    okBtn->setVisible(false);
    cancelBtn->setVisible(false);
    addBtn->setVisible(true);
    deleteBtn->setVisible(true);
}

void MainWindow::onCancelClicked()
{
    model->revertAll();
    model->submitAll();
    okBtn->setVisible(false);
    cancelBtn->setVisible(false);
    addBtn->setVisible(true);
    deleteBtn->setVisible(true);
}

void MainWindow::onReturnbtnClicked()
{
    model->setTable("UserInfo");
    tableView->setModel(model);
    //    ui->tableView->setColumnWidth(0,100);
    //    ui->tableView->setColumnWidth(1,160);
    //    ui->tableView->setColumnWidth(2,160);
    model->setHeaderData(0,Qt::Horizontal,"姓名");
    model->setHeaderData(1,Qt::Horizontal,"手机号码");
    model->setHeaderData(2,Qt::Horizontal,"电话号码");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    returnBtn->setVisible(false);
    searchBtn->setVisible(true);
    addBtn->setVisible(true);
    deleteBtn->setVisible(true);
}

void MainWindow::onDeletebtnClicked()
{
    //获取选中的model
    QItemSelectionModel * selectModel = tableView->selectionModel();
    //获取选中model的索引
    QModelIndexList list = selectModel->selectedRows();
    if(list.size() == 0)
    {
        QMessageBox::warning(this, tr("warning"),
                             tr("请选择要删除的行"),
                             QMessageBox::Ok);
    }
    else
    {
        int ret = QMessageBox::warning(this, tr("warning"),
                                       tr("你真的要删除吗?"),
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
    //提交
    model->submitAll();
    model->select();
}

void MainWindow::onSearchbtnClicked()
{
    QString where = lineEdit->text();
    QString str;
    //QString s = QString("%1").arg("%"+name+"%");
    qDebug()<<comboBox->currentIndex();

    if(comboBox->currentIndex()==0)
    {
        str = QString("name like '%1'").arg("%"+where+"%");
        qDebug()<<str;
    }
    if(comboBox->currentIndex() == 1)
    {
        str = QString("moblieNum like '%1'").arg("%"+where+"%");
    }
    if(comboBox->currentIndex() == 2)
    {
        str = QString("telNum like '%1'").arg("%"+where+"%");
    }

    //设置过滤器
    model->setFilter(str);
    model->select();
    //改变按钮显示状态
    searchBtn->setVisible(false);
    returnBtn->setVisible(true);
    addBtn->setVisible(false);
    deleteBtn->setVisible(false);
}

void MainWindow::onAddbtnClicked()
{
    //添加一条记录
    QSqlRecord record = model->record();
    int row = model->rowCount();
    model->insertRecord(row,record);
    addBtn->setVisible(false);
    deleteBtn->setVisible(false);
    okBtn->setVisible(true);
    cancelBtn->setVisible(true);
    //model->select();
    //model->submitAll();
}

void MainWindow::onTableViewDoubleClicked()
{
    //改变按钮显示状态
    addBtn->setVisible(false);
    deleteBtn->setVisible(false);
    cancelBtn->setVisible(true);
    okBtn->setVisible(true);
}

void MainWindow::onLineReturnPress()
{
    QString where = lineEdit->text();
    QString str;
    //QString s = QString("%1").arg("%"+name+"%");
    qDebug()<<comboBox->currentIndex();

    if(comboBox->currentIndex()==0)
    {
        str = QString("name like '%1'").arg("%"+where+"%");
        qDebug()<<str;
    }
    if(comboBox->currentIndex() == 1)
    {
        str = QString("moblieNum like '%1'").arg("%"+where+"%");
    }
    if(comboBox->currentIndex() == 2)
    {
        str = QString("telNum like '%1'").arg("%"+where+"%");
    }

    //设置过滤器
    model->setFilter(str);
    model->select();
    //改变按钮显示状态
    searchBtn->setVisible(false);
    returnBtn->setVisible(true);
    addBtn->setVisible(false);
    deleteBtn->setVisible(false);
}

void MainWindow::onComboBoxCurrentIndexChanged(int index)
{

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setMinimumHeight(515);
    this->setMinimumWidth(342);
    this->setMaximumHeight(515);
    this->setMaximumWidth(342);

    //comboBox
    comboBox = new QComboBox(this);
    comboBox->setGeometry(20,10,69,22);
    //comboBox->addItem("默认");
    comboBox->addItem("姓名");
    comboBox->addItem("手机号");
    comboBox->addItem("电话号");
    //int index;
    connect(comboBox,static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),this,[=](){
        if(lineEdit->text()!="")
        {
            MainWindow::onSearchbtnClicked();
        }
    });

    //查询按钮
    searchBtn = new QPushButton(this);
    searchBtn->setText("查询");
    searchBtn->setVisible(true);
    searchBtn->setGeometry(250,10,75,23);
    connect(searchBtn,&QPushButton::clicked,this,MainWindow::onSearchbtnClicked);

    //添加按钮
    addBtn = new QPushButton(this);
    addBtn->setText("添加");
    addBtn->setVisible(true);
    addBtn->setGeometry(60,480,75,23);
    connect(addBtn,&QPushButton::clicked,this,MainWindow::onAddbtnClicked);

    //确认按钮
    okBtn = new QPushButton(this);
    okBtn->setText("确认");
    okBtn->setVisible(false);
    okBtn->setGeometry(60,480,75,23);
    connect(okBtn,&QPushButton::clicked,this,MainWindow::onOkbtnClicked);

    //删除按钮
    deleteBtn = new QPushButton(this);
    deleteBtn->setText("删除");
    deleteBtn->setVisible(true);
    deleteBtn->setGeometry(230,480,75,23);
    connect(deleteBtn,&QPushButton::clicked,this,MainWindow::onDeletebtnClicked);

    //取消按钮
    cancelBtn = new QPushButton(this);
    cancelBtn->setText("取消");
    cancelBtn->setVisible(false);
    cancelBtn->setGeometry(230,480,75,23);
    connect(cancelBtn,&QPushButton::clicked,this,MainWindow::onCancelClicked);

    //返回按钮
    returnBtn = new QPushButton(this);
    returnBtn->setText("返回");
    returnBtn->setVisible(false);
    returnBtn->setGeometry(250,10,75,23);
    connect(returnBtn,&QPushButton::clicked,this,MainWindow::onReturnbtnClicked);

    //tableView
    tableView = new QTableView(this);
    tableView->setGeometry(10,40,321,421);
    connect(tableView,&QTableView::doubleClicked,this,MainWindow::onTableViewDoubleClicked);
    //lineEdit
    lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(100,10,141,20);
    connect(lineEdit,&QLineEdit::returnPressed,this,MainWindow::onLineReturnPress);


    qDebug()<<QSqlDatabase::drivers();
    //加载数据库驱动 采用SQLite数据库
    QSqlDatabase db =  QSqlDatabase::addDatabase("QSQLITE");
    //获取当前路径
    QDir dir(QDir::currentPath());
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
        bool ok = query.exec("create table UserInfo(name nvarchar(20), "
                             "moblieNum varchar(50),telNum varchar(50))");
        //创建成功标志
        qDebug()<<ok;
        //QSqlQuery query1;
        //创建种子文数据
        bool ok1 = query.exec("insert into UserInfo(name,moblieNum,telNum) "
                              "values('王五','13025401112','05535698256')");
        qDebug()<<ok1;
    }
    else{
        db.setDatabaseName("users.db");
        bool y = db.open();
        qDebug()<<y;

    }


    model = new QSqlTableModel(this);
    model->setTable("UserInfo");
    //tableView 关联model
    tableView->setModel(model);
    //    tableView->setColumnWidth(0,100);
    //    tableView->setColumnWidth(1,160);
    //    tableView->setColumnWidth(2,160);
    model->select();


    //设置表头
    model->setHeaderData(0,Qt::Horizontal,"姓名");
    model->setHeaderData(1,Qt::Horizontal,"手机号码");
    model->setHeaderData(2,Qt::Horizontal,"电话号码");

    //设置提交策略
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    //完成后关闭数据库
    //db.close();

}

MainWindow::~MainWindow()
{

}

