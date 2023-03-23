#include "hudmainwindow.h"

HUDMainWindow::HUDMainWindow(HFS *_hfs, QWidget *parent)
    : QMainWindow(parent), hfs(_hfs)
{
    ui.setupUi(this);

    ui.nav_hfs->setDefaultAction(new QAction(this));
    ui.nav_log->setDefaultAction(new QAction(this));
    ui.nav_scene->setDefaultAction(new QAction(this));
    ui.nav_qml->setDefaultAction(new QAction(this));
    ui.nav_screensaver->setDefaultAction(new QAction(this));

    ui.nav_hfs->defaultAction()->setProperty("page", "hfs");
    ui.nav_log->defaultAction()->setProperty("page", "log");
    ui.nav_scene->defaultAction()->setProperty("page", "scene");
    ui.nav_qml->defaultAction()->setProperty("page", "qml");
    ui.nav_screensaver->defaultAction()->setProperty("page", "screensaver");

    QObject::connect(ui.nav_hfs, SIGNAL(triggered(QAction*)), this, SLOT(showPage(QAction*)));
    QObject::connect(ui.nav_log, SIGNAL(triggered(QAction*)), this, SLOT(showPage(QAction*)));
    QObject::connect(ui.nav_scene, SIGNAL(triggered(QAction*)), this, SLOT(showPage(QAction*)));
    QObject::connect(ui.nav_qml, SIGNAL(triggered(QAction*)), this, SLOT(showPage(QAction*)));
    QObject::connect(ui.nav_screensaver, SIGNAL(triggered(QAction*)), this, SLOT(showPage(QAction*)));

    ui.hfstree->setModel(hfs);
}

HUDMainWindow::~HUDMainWindow()
{}

void HUDMainWindow::showPage(QAction *act)
{
    if (!act) return;
    QString str = act->property("page").toString();
    if (str == "hfs")
        ui.mainstack->setCurrentWidget(ui.hfsPage);
    else if (str == "log")
        ui.mainstack->setCurrentWidget(ui.logPage);
    else if (str == "scene")
        ui.mainstack->setCurrentWidget(ui.scenePage);
    else if (str == "qml")
        ui.mainstack->setCurrentWidget(ui.qmlPage);
    else if (str == "screensaver")
        ui.mainstack->setCurrentWidget(ui.screensaverPage);
}

