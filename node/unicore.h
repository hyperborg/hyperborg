#ifndef UNICORE_H
#define UNICORE_H

#include <QObject>
#include <QString>
#include <QThread>

#include <common.h>
#include <entity.h>

class UniCore : public QObject
{
Q_OBJECT
public:
    UniCore(QObject *parent=nullptr);
    ~UniCore();
};

#endif