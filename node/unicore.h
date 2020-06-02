#ifndef UNICORE_H
#define UNICORE_H

#include <QObject>
#include <QString>
#include <QThread>
#include <QTimer>

#include <common.h>
#include <entity.h>
#include "hsettings.h"
#include "coresocket.h"

class UniCore : public QObject
{
Q_OBJECT
public:
    UniCore(QObject *parent=nullptr);
    ~UniCore();

public slots:
    void init();

}; 

#endif