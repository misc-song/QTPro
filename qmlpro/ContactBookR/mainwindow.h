#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QPushButton>
#include <QDir>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QTableView>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QLineEdit>
#include <QSqlRecord>
#include <QComboBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    //QMenuBar *mBar;
    QComboBox *comboBox;

    QPushButton *okBtn;

    QPushButton *cancelBtn;

    QPushButton *returnBtn;

    QPushButton *deleteBtn;

    QPushButton *searchBtn;

    QPushButton *addBtn;

    QLineEdit *lineEdit;

    QTableView *tableView;

    QSqlTableModel *model;

private slots:

    void onOkbtnClicked();

    void onCancelClicked();

    void onReturnbtnClicked();

    void onDeletebtnClicked();

    void onSearchbtnClicked();

    void onAddbtnClicked();

    void onTableViewDoubleClicked();

    void onLineReturnPress();

    void onComboBoxCurrentIndexChanged(int index);

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
