#include "widget.h"
#include "ui_widget.h"
#include<QFileDialog>
#include<QAxObject>
#include<QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);



}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_4_clicked()
{
    QString filepath=QFileDialog::getOpenFileName(this,tr("Open Excle File"),".",tr("Microsoft Office (*.xlsx)"));
    if(!filepath.isEmpty())
    {
        QAxObject *excel = new QAxObject(this);
        excel->setControl("Excel.Application");//连接Excel控件
        excel->dynamicCall("SetVisible(bool)", false); // 这句话如果是office2013中一定要，否则会无法读取文件

        QAxObject *workbooks = NULL;
        QAxObject *workbook = NULL;
        workbooks = excel->querySubObject("WorkBooks");

        workbook = workbooks->querySubObject("Open(QString&)", filepath);
        QAxObject * worksheets = workbook->querySubObject("WorkSheets"); // 获取打开的excel中所有的工作sheet
        QAxObject * worksheet = worksheets->querySubObject("Item(int)", 1); // 获取第一个工作sheet
        QAxObject * usedrange = worksheet->querySubObject("UsedRange");//获取该sheet的使用范围对象
        QAxObject * rows = usedrange->querySubObject("Rows");//获取所有的行
        QAxObject * columns = usedrange->querySubObject("Columns");//获取所有的列

        /*获取行数和列数*/

        int intCols = columns->property("Count").toInt();//列数
        int intRows = rows->property("Count").toInt(); //行数
        int intRowStart = rows->property("Row").toInt();//第一行
        int intColStart = columns->property("Column").toInt();//第一列

        qDebug()<<"行数为："<<intCols<<"列数为："<<intRows<<"第一行"<<intRowStart<<"第一列"<<intColStart<<endl;
        QVector<QAxObject*> cells;
        /*获取excel内容*/
        //int cnt = 0;

        for (int i = 1; i <= intRows; i++)  //行
        {

            //            cnt++;
            //            int iter = intColStart;
            for(int j =1;j<=intCols;j++)//列
            {
                QAxObject* temp = worksheet->querySubObject("Cells(int,int)", i, j);
                cells.append(temp);

                delete(temp);
            }

            //QAxObject* cell1 = worksheet->querySubObject("Cells(int,int)", i, iter++);
            //QAxObject* cell2 = worksheet->querySubObject("Cells(int,int)", i, iter++);
            //QAxObject* cell3 = worksheet->querySubObject("Cells(int,int)", i, iter++);


            //QString value1 = index_c->dynamicCall("Value2()").toString();
            //QString value2 = problem_c->dynamicCall("Value2()").toString();
            //QString value3 = selectA_c->dynamicCall("Value2()").toString();

        }
        qDebug()<<"共有："<<cells.size();
        QString str = cells.at(2)->dynamicCall("Value2()").toString();
        qDebug()<<str;
        //        for(int j = 0;j<cells.count();j++)
        //        {
        //            //QString str = cells[j]->dynamicCall("Value2()").toString();
        //            qDebug()<<cells;//->dynamicCall("Value2()").toString();;
        //        }
    }
}

void Widget::on_pushButton_3_clicked()
{
    QString strFile = QFileDialog::getOpenFileName(this,QStringLiteral("选择Excel文件"),"",tr("Exel file(*.xls *.xlsx)"));
    if (strFile.isEmpty())
    {
        return;
    }
    QAxObject excel("Excel.Application"); //加载Excel驱动
    excel.setProperty("Visible", false); //不显示Excel界面，如果为true会看到启动的Excel界面
    QAxObject* pWorkBooks = excel.querySubObject("WorkBooks");
    pWorkBooks->dynamicCall("Open (const QString&)", strFile);//打开指定文
    QAxObject* pWorkBook = excel.querySubObject("ActiveWorkBook");
    QAxObject* pWorkSheets = pWorkBook->querySubObject("Sheets");//获取工作表
    int nSheetCount = pWorkSheets->property("Count").toInt();  //获取工作表的数目
    if(nSheetCount > 0)
    {
        QAxObject* pWorkSheet = pWorkBook->querySubObject("Sheets(int)", 1);//获取第一张表
        int nSection = 20;
        int nSectionEnd = 0;
        QVariantList params;
        int nRowEnd = 20;
        QVariant varData;
        for (int i = 1; i <= nRowEnd; i += nSection)
        {
            nSectionEnd = i+nSection - 1;
            if (nSectionEnd > nRowEnd)
            {
                nSectionEnd = nRowEnd;
            }
            char cZimu = 1 + 64; //1-26分别代表A-Z，符合Excel表的列标识
            //Ai至Ai+nSectionEnd的数据,这里为了测试一次是读取20条
            params <<QString("%1%2").arg(cZimu).arg(i)<<QString("%1%2").arg(cZimu).arg(nSectionEnd);
            QAxObject* pCell = pWorkSheet->querySubObject("Range(QVariant,QVariant)",params);
            varData = pCell->dynamicCall("Value2()");
            //            qDebug()<<varData;
            QVariantList varList = varData.toList(); //解除第一层List
            if(varList.count() <= 0)//防止内存溢出
            {
                qDebug()<<"无数据！";
                pWorkBooks->dynamicCall("Close()");
                return;
            }
            QVariantList varLstData = varList[0].toList(); //解除第二层List   if(varLstData.count() <= 0)
            {
                qDebug()<<"无数据！";
                pWorkBooks->dynamicCall("Close()");
                return;
            }
            //判断数据类型，防止转化出错。
            if(QString(varLstData[0].typeName()) == "QString")
            {
                QString str = varLstData[0].toString(); //取出数据
                qDebug()<<"字符串："+str;
            }
            if(QString(varLstData[0].typeName()) == "double")
            {
                double dData = varLstData[0].toDouble(); //取出数据
                qDebug()<<dData; //注意，int型读出来也是double，所以一定要注意转化
            }
            //
        }

        pWorkBooks->dynamicCall("Close()");
    }



}
