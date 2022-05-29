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
#include <QQmlContext>
#include <QByteArray>
#include <QQmlComponent>

#include "buffer.h"
#include "pluginslot.h"
#include "hentity.h"
#include "hentityfactory.h"
#include "hfs.h"
#include "hud.h"
#include "hudfactory.h"

class Slotter : public QThread
{
Q_OBJECT
public:
	Slotter(HEntityFactory *hf, QObject* parent = nullptr);
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
	void loadConfiguration(QJsonObject& obj);
	void saveConfiguration(QJsonObject& obj);
	const HFS* getHFS() { return hfs; }

public slots:
	void init();
	
signals:
	void logLine(int severity, QString line, QString source);
	void newPackReady(DataPack* pack);

protected:
	void log(int severity, QString line, QString src="SLOTTER");
	
	// convinience function for sending pack downward (UC) direction
	void sendPack(DataPack *pack);

	QObject* getObjectByName(QString name);
	void connectHUDtoHFS();

private:
	int processPackFromUniCore();

// Plugin communication and relation handling
private slots:
	void datapackFromHyObj(DataPack *pack);

	void executeCommand(int cmd, DataPack *pack);

signals:

private:
	PackBuffer* inbound_buffer;
	PackBuffer* req_buffer;
	QWaitCondition* waitcondition;
	QMutex* slotter_mutex;

	QList<PluginSlot *> pluginslots;
	QJsonObject json_config;		// Contains all plugin related configuration

	HEntityFactory *hfact;
	QHash<QString, QObject*> hobs;
	HFS* hfs;

	HUDQMLEngine* qmle;
	QObject* mainPage;
};

#endif
