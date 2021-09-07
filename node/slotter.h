/*HYPERBORG SLOTTER

The main functionality of the slotter is to create a general interface for all devices connected to this node.
*/

#ifndef SLOTTER_H
#define SLOTTER_H

#include "common.h"

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
#include <QJsonObject>

#include "buffer.h"
#include "pluginslot.h"
#include "hentity.h"
#include "hentityfactory.h"

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
	void setReqBuffer(PackBuffer* b)
	{
		req_buffer = b;
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
	void loadConfiguration(QJsonObject& obj);
	void saveConfiguration(QJsonObject& obj);

public slots:
	void init();
	
signals:
	void logLine(int severity, QString line, QString source);
	void newPackReady(DataPack* pack);

protected slots:

protected:
	void log(int severity, QString line);
	// convinience function for sending pack downward (UC) direction
	void sendPack(DataPack *pack);

private:
	int processPackFromUniCore();
	int processPackFromEntityFactory();

private:
	PackBuffer* inbound_buffer;
	PackBuffer* req_buffer;
	QWaitCondition* waitcondition;
	QMutex* slotter_mutex;

	QList<PluginSlot *> pluginslots;
	QJsonObject json_config;		// Contains all plugin related configuration

	HEntityFactory *hfact;
};

#endif
