/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LUFTDATEN_H
#define LUFTDATEN_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class luftdaten : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "luftdaten.json");
    Q_INTERFACES(HyPluginInterface);
public:
    luftdaten(QObject *parent=nullptr);
    ~luftdaten();

    QString name() 		{ return "luftdaten"; }
    QString description()	{ return "Support for Luftdaten stations."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void _async_fixup_sensor_id();
	void async_setup();
	void async_setup_entry();
	void refresh_sensors();
	void async_unload_entry();
	void __init__();
	void async_update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif