#ifndef BUFFER_H
#define BUFFER_H

#include <QObject>
#include <QVector>
#include <QWaitCondition>
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>

#include "common.h"
class PackBuffer : public QObject
{
    Q_OBJECT
public:
    PackBuffer(QWaitCondition* wc, QObject* parent = nullptr);
    ~PackBuffer();
    DataPack* takeFirst();

public slots:
    void addPack(DataPack* pack);

signals:
    void newData();

private:
    QVector<DataPack*> packs;
    QWaitCondition* waitcondition;
    QMutex* packmutex;
};


#endif