/*HYPERBORG SLOTTER

The main functionality of the slotter is to create a general interface for all devices connected to this node.
*/

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
#include <QHash>
#include <QHashIterator>

#include "common.h"
#include "buffer.h"
#include "pluginslot.h"

class Slotter : public QThread
{
Q_OBJECT
public:
	Slotter(QObject* parent = nullptr);
	~Slotter();

	QWaitCondition* getWaitCondition()   { return waitcondition;  }
	void setInboundBuffer(PackBuffer* b)
	{
		inbound_buffer = b;
	}
	void run();
	void addPluginSlot(PluginSlot *slot)
	{
	    pluginslots.append(slot);
	}

	void clearPluginSlots()
	{
	    pluginslots.clear();
	    // we do not destroy plugins here, nodecore should unregister their instances
	}

	// Iterate over all plugins and create all relevant entites from them
	void activatePlugins();

public slots:
	void init();

signals:
	void logLine(int severity, QString line);
	void newPackReady(DataPack* pack);

protected:
	void log(int severity, QString line);

private:
	int processPackFromUniCore();

private:
	PackBuffer* inbound_buffer;
	QWaitCondition* waitcondition;
	QMutex* slotter_mutex;

	QList<PluginSlot *> pluginslots;
};

#endif
