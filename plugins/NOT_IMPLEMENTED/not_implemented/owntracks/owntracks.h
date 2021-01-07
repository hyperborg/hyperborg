/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef OWNTRACKS_H
#define OWNTRACKS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class owntracks : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "owntracks.json");
    Q_INTERFACES(HyPluginInterface);
public:
    owntracks(QObject *parent=nullptr);
    ~owntracks();

    QString name() 		{ return "owntracks"; }
    QString description()	{ return "Support for OwnTracks."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void async_remove_entry();
	void async_connect_mqtt();
	void async_handle_mqtt_message();
	void handle_webhook();
	void __init__();
	void async_valid_accuracy();
	void set_async_see();
	void async_see();
	void async_see_beacons();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif