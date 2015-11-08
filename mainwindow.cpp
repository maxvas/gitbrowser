#include "mainwindow.h"
#include "mainwindow_ui.h"
#include <iostream>
#include "repotree/treeitemdelegate.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QJS rootItem;
    rootItem["name"] = "Репозитории";
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
    n5["name"] = "Прочие отчеты";
    n5["type"] = "folder";
    n1["children"][0] = n4;
    n1["children"][1] = n5;
    rootItem["children"][0] = n1;
    rootItem["children"][1] = n2;
    rootItem["children"][2] = n3;
    QJSModel *rm = new QJSModel(rootItem);
    rm->setIcon("folder", "://images/folder.png");
    ui->treeView->setModel(rm);
}

MainWindow::~MainWindow()
{
    delete ui;
}
