#pragma once

#include <QMainWindow>
#include "ui_hudmainwindow.h"

class HUDMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    HUDMainWindow(QWidget *parent = nullptr);
    ~HUDMainWindow();

private:
    Ui::HUDMainWindowClass ui;
};
