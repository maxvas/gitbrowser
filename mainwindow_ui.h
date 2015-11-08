#ifndef UI_FILESBROWSER_H
#define UI_FILESBROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QToolBar *toolBar;
    QToolBar *navigationPanel;
    QSplitter *splitter;
    QTreeView *treeView;
    QListView *listView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(640, 400);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        toolBar = new QToolBar(centralWidget);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setIconSize(QSize(20, 20));

        verticalLayout->addWidget(toolBar);

        navigationPanel = new QToolBar(centralWidget);
        navigationPanel->setObjectName(QStringLiteral("navigationPanel"));
        navigationPanel->setIconSize(QSize(20, 20));

        verticalLayout->addWidget(navigationPanel);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(0);
        treeView = new QTreeView(splitter);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setMinimumWidth(50);
        treeView->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        splitter->addWidget(treeView);
        listView = new QListView(splitter);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setAlternatingRowColors(true);
        splitter->addWidget(listView);
        splitter->setSizes(QList<int>()<<200<<10);
        splitter->setStretchFactor(1, 1);

        verticalLayout->addWidget(splitter);


        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\236\320\261\320\267\320\276\321\200 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\276\320\262", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESBROWSER_H
