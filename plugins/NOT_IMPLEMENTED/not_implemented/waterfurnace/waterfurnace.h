/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef WATERFURNACE_H
#define WATERFURNACE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class waterfurnace : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "waterfurnace.json");
    Q_INTERFACES(HyPluginInterface);
public:
    waterfurnace(QObject *parent=nullptr);
    ~waterfurnace();

    QString name() 		{ return "waterfurnace"; }
    QString description()	{ return "Support for Waterfurnaces."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void __init__();
	void _reconnect();
	void run();
	void register();
	void shutdown();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif