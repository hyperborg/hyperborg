#include "hudmainwindow.h"

HUDMainWindow::HUDMainWindow(HFS *_hfs, QWidget *parent)
    : QMainWindow(parent), hfs(_hfs), ssaver_timeout(0)
{
    ui.setupUi(this);
    QGuiApplication::instance()->installEventFilter(this);
    QObject::connect(&ssaver_timer, SIGNAL(timeout()), this, SLOT(checkScreenSaverState()));
    ssaver_timer.setSingleShot(false);
    ssaver_timer.start(1000);

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

bool HUDMainWindow::eventFilter(QObject* watched, QEvent* event)
{
    switch (event->type())
    {
        case QEvent::KeyPress:
        case QEvent::MouseButtonPress:
        case QEvent::MouseButtonDblClick:
        case QEvent::MouseMove:
            if (ssaver_timeout < 0)
            {
                wakeUpFromScreenSaver();
            }
            ssaver_timeout = 0;
            break;
    }
    QObject::eventFilter(watched, event);
    return false;
}

void HUDMainWindow::checkScreenSaverState()
{
    if (ssaver_timeout >= 0)
    {
        ssaver_timeout++;
        if (ssaver_timeout > 5)
        {
            enterScreenSaverMode();
        }
    }
    else
    {
        ssaver_timeout--;
        if (ssaver_timeout < -30)
        {
            ssaver_timeout = -1;
            loadScreenSaverPicture();
        }
    }
}

void HUDMainWindow::enterScreenSaverMode()
{
    ssaver_lastused = ui.mainstack->currentIndex();
    ssaver_timeout = -1;
    ui.mainstack->setCurrentWidget(ui.screensaverPage);
    loadScreenSaverPicture();
}

void HUDMainWindow::wakeUpFromScreenSaver()
{
    ui.mainstack->setCurrentIndex(ssaver_lastused);
    ssaver_timeout = 0;
}

void HUDMainWindow::loadScreenSaverPicture()
{
    QString picsdir;
#if LINUX
    picsdir = "/etc/hyperborg/pics";
#else
    picsdir = "c:/hyperborg/pics";
#endif

    QDir dir(picsdir);
    QStringList filters;
    filters << "*.png" << "*.PNG" << "*.jpeg" << "*.JPEG" << "*.jpg" << "*.jpeg";
    dir.setNameFilters(filters);
    QStringList lst = dir.entryList(QDir::Files);
    if (lst.count())
    {
        int idx = rndgen.bounded(lst.count());
        QPixmap px(picsdir + "/" + lst.at(idx));
        px = px.scaled(ui.label_ssaver->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui.label_ssaver->setPixmap(px);
    }

}