#include "filesbrowser.h"
#include <QApplication>
#include <QDir>
#include "mainwindow.h"
#include <QQmlApplicationEngine>
#include <QtQml>
#include "repotree/qjsmodel.h"
#include <QJS>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QQmlApplicationEngine engine;
//    engine.rootContext()->setContextProperty("repoModel", rm);
//    engine.load(QUrl(QStringLiteral("qrc:///qml/MainWindow.qml")));
//    GitBrowser window(QDir::homePath()+"/lims/documents");
//    window.readRepoConfigOrAskUser();
//    window.addToolBarAction("settings");
//    window.addToolBarAction("new-document");
//    window.show();
    MainWindow window;
    window.show();
    return a.exec();
}
