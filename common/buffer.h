#ifndef BUFFER_H
#define BUFFER_H

#include <QObject>
#include <QVector>
#include <QWaitCondition>
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>

#include "common.h"

class DataBuffer : public QObject
{
	Q_OBJECT
public:
	DataBuffer(QWaitCondition *wc, QObject *parent=nullptr);
	~DataBuffer();
	DataBlock* takeFirst();

public slots:
	void addBlock(DataBlock* block);

signals:
	void newData();

private:
	QVector<DataBlock*> blocks;
	QWaitCondition* waitcondition;
	QMutex* blockmutex;
	QMutex* buffermutex;
};

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