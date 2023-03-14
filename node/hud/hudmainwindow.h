#pragma once

#include <QMainWindow>
#include <QGridLayout>

#include "ui_hudmainwindow.h"

class HUDMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    HUDMainWindow(QWidget *parent = nullptr);
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

protected slots:
    void showPage(QAction *act);

private:
    Ui::HUDMainWindowClass ui;
};
