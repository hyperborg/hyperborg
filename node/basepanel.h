#ifndef BasePanel_H
#define BasePanel_H

#include <QMainWindow>
#include <QTime>
#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QtMath>
#include <QDateTime>
#include <QTime>
#include <QDate>
#include <QTimer>
#include <QButtonGroup>
#include <QDebug>
#include <QFile>
#include <QStackedWidget>
#include <QLCDNumber>
#include <QEvent>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QMessageBox>
#include <QEvent>
#include <QAction>
#include <QIcon>
#include <QPixmap>

#include "ui_basepanel.h"
#include "slotter.h"
#include "codeeditor.h"

class BasePanel : public QMainWindow
{
Q_OBJECT
public:
    BasePanel(QWidget *parent=NULL, Qt::WindowFlags flags=0);
    ~BasePanel();

    void setSlotter(Slotter *slotter);

public slots:
    void clockTimerTimeout();
    void slot_logLine(int severity, QString str, QString source=QString());
    void slot_logLineHUD(QString str);

protected slots:
    void activateScreenSaver();
    void showTrayMessage(QString str);

protected:
    bool eventFilter(QObject *obj, QEvent *ev) override;
    void closeEvent(QCloseEvent* event);
    void setupForTray();

signals:
    void switchEvent(QString name, QString value);
    void timeChanged(QString time);
    void dateChanged(QString date);
    void logLine(int severity, QString str, QString source);
    void logLineHUD(QString str);

private:
    Ui::BasePanel ui;
    QTimer clocktimer;
    int ss_timeout;
    QTimer screensaver;
    CodeEditor* codeeditor;

    // elements for tray menu
    QAction* minimizeAction;
    QAction* maximizeAction;
    QAction* restoreAction;
    QAction* quitAction;

    QSystemTrayIcon* trayIcon;
    QMenu* trayIconMenu;
};


#endif