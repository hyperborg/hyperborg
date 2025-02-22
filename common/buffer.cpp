#include "buffer.h"

PackBuffer::PackBuffer(QObject* parent, QWaitCondition* wc)
    : QObject(parent), waitcondition(wc), packmutex(std::make_unique<QMutex>())
{
}

PackBuffer::~PackBuffer()
{
    // No need to manually delete packmutex and waitcondition as they are managed by smart pointers
}

void PackBuffer::addPack(DataPack* pack)
{
    QMutexLocker locker(packmutex.get());
    packs.append(pack);
    if (waitcondition)
    {
        waitcondition->wakeAll();
    }
    emit newData();
}

DataPack* PackBuffer::takeFirst()
{
    QMutexLocker locker(packmutex.get());
    if (!packs.isEmpty())
    {
        return packs.takeFirst();
    }
    return nullptr;
}