/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GEONETNZ_VOLCANO_H
#define GEONETNZ_VOLCANO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class geonetnz_volcano : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "geonetnz_volcano.json");
    Q_INTERFACES(HyPluginInterface);
public:
    geonetnz_volcano();
    ~geonetnz_volcano();

    QString name() 		{ return "geonetnz_volcano"; }
    QString description()	{ return "The GeoNet NZ Volcano integration."; }

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
	void last_update();
	void last_update_successful();
	void _generate_entity();
	void _update_entity();
	void _remove_entity();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif