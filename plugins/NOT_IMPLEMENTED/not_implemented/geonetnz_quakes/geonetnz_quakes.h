/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GEONETNZ_QUAKES_H
#define GEONETNZ_QUAKES_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class geonetnz_quakes : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "geonetnz_quakes.json");
    Q_INTERFACES(HyPluginInterface);
public:
    geonetnz_quakes(QObject *parent=nullptr);
    ~geonetnz_quakes();

    QString name() 		{ return "geonetnz_quakes"; }
    QString description()	{ return "The GeoNet NZ Quakes integration."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void __init__();
	void async_init();
	void update();
	void async_update();
	void async_stop();
	void async_event_new_entity();
	void get_entry();
	void status_info();
	void _generate_entity();
	void _update_entity();
	void _remove_entity();
	void _status_update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif