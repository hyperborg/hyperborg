/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SEARCH_H
#define SEARCH_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class search : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "search.json");
    Q_INTERFACES(HyPluginInterface);
public:
    search();
    ~search();

    QString name() 		{ return "search"; }
    QString description()	{ return "The Search integration."; }

protected:
    	void async_setup();
	void websocket_search_related();
	void __init__();
	void async_search();
	void _add_or_resolve();
	void _resolve_area();
	void _resolve_device();
	void _resolve_entity();
	void _resolve_automation();
	void _resolve_script();
	void _resolve_group();
	void _resolve_scene();
	void _resolve_config_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif