#ifndef SLOTTER_H
#define SLOTTER_H

#include <QObject>
#include <QString>
#include <QMutex>
#include <QVector>
#include <QWaitCondition>
#include <QThread>
#include <QTimer>
#include <QList>

#include "common.h"
#include "buffer.h"
#include "entity.h"

class Slotter : public QThread
{
Q_OBJECT
public:
	Slotter(QObject* parent = nullptr);
	~Slotter();

	void registerEntity(Entity* entity);
	void unregisterEntity(Entity* entity);

	QWaitCondition* getWaitCondition()   { return waitcondition;  }
	void setInboundBuffer(PackBuffer* b) 
	{ 
		inbound_buffer = b;    
	}
	void run();

public slots:
	void init();

signals:
	void logLine(int severity, QString line);
	void newPackReady(DataPack* pack);

protected slots:
	void runTest();

protected:
	void log(int severity, QString line);

private:
	int processPackFromUniCore();

private:
	PackBuffer* inbound_buffer;
	QWaitCondition* waitcondition;
	QMutex* slotter_mutex;
	QTimer* testtimer;
	QList<Entity*> eslots;
};

#endif
