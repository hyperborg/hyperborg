#include "buffer.h"

DataBuffer::DataBuffer(QWaitCondition *wc, QObject* parent) : QObject(parent)
{
    waitcondition = wc;
    blockmutex = new QMutex();
}

DataBuffer::~DataBuffer()
{
    delete(blockmutex);
    delete(waitcondition);
}

void DataBuffer::addBlock(DataBlock *block)
{
    QMutexLocker locker(blockmutex);
    blocks.append(block);
    if (waitcondition) waitcondition->wakeAll();
    emit newData();
}

DataBlock* DataBuffer::takeFirst()
{
    printf("DB::takeFirst is called\n");
    QMutexLocker locker(blockmutex);
    printf("DB::takeFirst inside\n");
    DataBlock* db = NULL;
    if (blocks.count())
    {
    	db = blocks.takeFirst();
    }
    printf("DB::takeFirst is returns %p\n", db);
    return db;
}

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
	QMutexLocker locker(packmutex);
	packs.append(pack);
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