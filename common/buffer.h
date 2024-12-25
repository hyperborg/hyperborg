#pragma once

#include <QObject>
#include <QVector>
#include <QWaitCondition>
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>
#include <memory>

#include "common.h"
#include "datapack.h"

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
    std::unique_ptr<QMutex> packmutex;
};