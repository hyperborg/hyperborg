#include "buffer.h"
PackBuffer::PackBuffer(QWaitCondition* wc, QObject* parent) : QObject(parent)
{
    waitcondition = wc;
    packmutex = new QMutex();
}

PackBuffer::~PackBuffer()
{
    delete(packmutex);
    delete(waitcondition);
}

void PackBuffer::addPack(DataPack* pack)
{
    packmutex->lock();
    packs.append(pack);
    packmutex->unlock();
    if (waitcondition) waitcondition->wakeAll();
    emit newData();
}

DataPack* PackBuffer::takeFirst()
{
    QMutexLocker locker(packmutex);
    DataPack* db = NULL;
    if (packs.count())
    {
    	db = packs.takeFirst();
    }
    return db;
}