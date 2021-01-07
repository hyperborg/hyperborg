/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HIVE_H
#define HIVE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class hive : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "hive.json");
    Q_INTERFACES(HyPluginInterface);
public:
    hive(QObject *parent=nullptr);
    ~hive();

    QString name() 		{ return "hive"; }
    QString description()	{ return "Support for the Hive devices and services."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void heating_boost();
	void hot_water_boost();
	void refresh_system();
	void wrapper();
	void __init__();
	void async_added_to_hass();
	void _update_callback();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif