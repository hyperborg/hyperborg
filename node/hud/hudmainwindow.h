#pragma once

#include <QMainWindow>
#include <QGridLayout>
#include <QTreeView>
#include <QDir>
#include <QString>
#include <QStringList>
#include <QRandomGenerator>

#include "common.h"
#include "hfs.h"

#include "ui_hudmainwindow.h"

class HUDMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    HUDMainWindow(HFS *_hfs, QWidget *parent = nullptr);
    ~HUDMainWindow();

    void addQuickWidget(QWidget *wid)
    {
        if (!wid) return;
        wid->setParent(this);
        ui.qmllayout->addWidget(wid);
    }

    void invalidate()
    {
        ui.qmllayout->invalidate();
    }

    bool eventFilter(QObject* watched, QEvent* event);

protected slots:
    void showPage(QAction *act);
    void checkScreenSaverState();
    void enterScreenSaverMode();
    void wakeUpFromScreenSaver();
    void loadScreenSaverPicture();

private:
    Ui::HUDMainWindowClass ui;
    HFS *hfs;
    int ssaver_timeout;
    QTimer ssaver_timer;
    int ssaver_lastused;            // Last visible page before screensaver is kicked in
    QRandomGenerator rndgen;
};
