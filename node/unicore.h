#ifndef UNICORE_H
#define UNICORE_H

#include <QObject>
#include <QString>
#include <QThread>
#include <QTimer>

#include <common.h>
#include <entity.h>
#include "hsettings.h"


class UniCore : public QObject
{
Q_OBJECT
public:
    UniCore(QObject *parent=nullptr);
    ~UniCore();

public slots:
    void incomingData(DataBlock* block);

signals:
    void outgoingData(DataBlock* block);
    void logLine(int severity, QString str);

public slots:
    void init();

private:
    void log(int severity, QString line);
    bool checkIntegrity(DataBlock* block);
    bool checkACL(DataBlock* block);
    bool checkWhatever(DataBlock* block);


}; 

#endif