/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TUYA_H
#define TUYA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class tuya : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "tuya.json");
    Q_INTERFACES(HyPluginInterface);
public:
    tuya(QObject *parent=nullptr);
    ~tuya();

    QString name() 		{ return "tuya"; }
    QString description()	{ return "Support for Tuya Smart devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void load_devices();
	void poll_devices_update();
	void force_update();
	void __init__();
	void async_added_to_hass();
	void object_id();
	void unique_id();
	void available();
	void update();
	void _delete_callback();
	void _update_callback();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif