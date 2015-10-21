#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "repotree/qjsmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QJSModel *rm;
};

#endif // MAINWINDOW_H
