#include "syncdialog.h"
#include "ui_syncdialog.h"
#include <QLabel>
#include <QMovie>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQuickView>
#include <QQuickWidget>
#include <QDebug>
#include <QQuickItem>

SyncDialog::SyncDialog(QWidget *parent) :
    QLabel(parent)
{
//    this->setGeometry(parent->geometry());
    this->setStyleSheet("background-color: transparent;");
//    this->setStyleSheet("background-color: rgba(119, 136, 153, 128);");
//    QVBoxLayout *mainLayout = new QVBoxLayout(this);
//    syncImage = new QMovie(":/images/sync.gif");
//    syncImage->setScaledSize(QSize(50, 50));
//    iconLabel = new QLabel();
//    iconLabel->setMovie(syncImage);
//    iconLabel->setAlignment(Qt::AlignCenter);
//    iconLabel->setStyleSheet("background-color: transparent;");
//    titleLabel = new QLabel("Синхронизация...");
//    titleLabel->setStyleSheet("background-color: transparent;");
//    titleLabel->setAlignment(Qt::AlignCenter);
//    progress = new QProgressBar;
//    progress->setMinimumWidth(200);
//    progress->setMaximumHeight(15);
//    progress->setStyleSheet("border: 1px solid grey; background-color: green;");
//    progress->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
//    progress->setMaximum(100);
//    progress->setTextVisible(false);
//    QVBoxLayout *tpLayout = new QVBoxLayout;
//    tpLayout->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding));
//    tpLayout->addWidget(titleLabel);
//    tpLayout->addWidget(progress);
//    tpLayout->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding));

//    QWidget *centralWidget = new QWidget;
//    QHBoxLayout *hLayout = new QHBoxLayout;
//    hLayout->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum));
//    hLayout->addWidget(iconLabel);
//    hLayout->addLayout(tpLayout);
//    hLayout->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum));
//    centralWidget->setLayout(hLayout);
//    centralWidget->setStyleSheet("background-color: white;");
//    centralWidget->setMinimumWidth(210);
//    centralWidget->setMaximumWidth(210);

//    QHBoxLayout *hCentralLayout = new QHBoxLayout;
//    hCentralLayout->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding));
//    hCentralLayout->addWidget(centralWidget);
//    hCentralLayout->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding));

//    mainLayout->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding));
//    mainLayout->addLayout(hCentralLayout);
//    mainLayout->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding));
//    iconLabel->setMovie(syncImage);
//    this->setLayout(mainLayout);
////    this->hide();
//    progress->setVisible(false);

    QQuickWidget *qw = new QQuickWidget(QUrl(QStringLiteral("qrc:/WaitingWindow.qml")), this);
    qw->setResizeMode(QQuickWidget::SizeRootObjectToView);
    qw->setAttribute(Qt::WA_AlwaysStackOnTop);
    qw->setClearColor(Qt::transparent);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(0);
    layout->addWidget(qw);
    this->setLayout(layout);
    rootElement = qw->rootObject();
    connect(rootElement, SIGNAL(retry()), this, SIGNAL(retry()));
}

SyncDialog::~SyncDialog()
{
}

void SyncDialog::showSynch(QString title, bool withProgressBar)
{
    QMetaObject::invokeMethod(rootElement, "showSync");
    this->show();
}

void SyncDialog::stop()
{
    this->hide();
}

void SyncDialog::setProgress(int value)
{
//    progress->setValue(value);
}

void SyncDialog::showError(QString errorString)
{
    QMetaObject::invokeMethod(rootElement, "showError", Q_ARG(QVariant, errorString));
    this->show();
}

void SyncDialog::clear()
{

}
