#ifndef WIDGET_H
#define WIDGET_H
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QWidget>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDir>
#include <QMessageBox>
#include <QPushButton>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
QPushButton OkBtn;
QPushButton CancelBtn;
QPushButton ReturnBtn;
private slots:
    void on_AddBtn_clicked();

    void on_DeleteBtn_clicked();

    void on_SearchBtn_clicked();

    void on_SearchLEdit_returnPressed();

    void on_Before_Insert();

    void on_Before_Delete();

    void onOKBtn();

    void onCancelBtn();

    void onReturnBtn();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_SearchLEdit_textChanged(const QString &arg1);

private:
    Ui::Widget *ui;
    QSqlTableModel *model;
};

#endif // WIDGET_H
