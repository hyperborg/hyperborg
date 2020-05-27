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

#include "ui_basepanel.h"

class BasePanel : public QMainWindow
{
Q_OBJECT
public:
    BasePanel(QWidget *parent=NULL, Qt::WindowFlags flags=0);
    ~BasePanel();

public slots:
    void clockTimerTimeout();
    void buttonToggled(int, bool);

protected slots:
    void setStatus(QString key, QString value);
    void activateScreenSaver();

protected:
    bool eventFilter(QObject *obj, QEvent *ev) override;

signals:
    void switchEvent(QString name, QString value);

private:
    Ui::BasePanel ui;
    QTimer clocktimer;
    int ss_timeout;
    QTimer screensaver;
    QButtonGroup *bg;
    bool school_wakeup;
};


#endif