#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "repotree/treeitemdelegate.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QJS rootItem;
    rootItem["name"] = "Хранилища";
    QJS n1;
    n1["name"] = "Отчеты";
    n1["type"] = "folder";
    QJS n2;
    n2["name"] = "Карточки";
    n2["type"] = "folder";
    QJS n3;
    n3["name"] = "Инструкции";
    n3["type"] = "folder";
    QJS n4;
    n4["name"] = "Генетические отчеты";
    n4["type"] = "folder";
    QJS n5;
    n4["name"] = "Прочие отчеты";
    n4["type"] = "folder";
    n1["children"][0] = n4;
    n1["children"][1] = n5;
    rootItem["children"][0] = n1;
    rootItem["children"][1] = n2;
    rootItem["children"][1] = n3;
    cout<<rootItem.toJson().toStdString();
    cout.flush();
    rm = new QJSModel(rootItem, this);
    rm->setIcon("folder", "://images/folder.png");
    ui->treeView->setModel(rm);
    ui->treeView->setItemDelegate(new TreeItemDelegate(ui->treeView));
    ui->treeView->viewport()->setAttribute(Qt::WA_Hover);
    ui->treeView->setStyleSheet("QTreeView {\
                                background-color: white;\
                            }");
}

MainWindow::~MainWindow()
{
    delete ui;
}
