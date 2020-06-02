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
    void slot_logLine(QString str);

protected slots:
    void activateScreenSaver();

protected:
    bool eventFilter(QObject *obj, QEvent *ev) override;

signals:
    void switchEvent(QString name, QString value);
    void timeChanged(QString time);
    void dateChanged(QString date);
    void logLine(QString str);

private:
    Ui::BasePanel ui;
    QTimer clocktimer;
    int ss_timeout;
    QTimer screensaver;
};


#endif