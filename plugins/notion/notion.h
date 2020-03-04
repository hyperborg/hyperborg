/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NOTION_H
#define NOTION_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class notion : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "notion.json");
    Q_INTERFACES(HyPluginInterface);
public:
    notion();
    ~notion();

    QString name() 		{ return "notion"; }
    QString description()	{ return "Support for Notion."; }

protected:
    	void  async_setup();
	void  async_setup_entry();
	void  refresh();
	void  async_unload_entry();
	void  register_new_bridge();
	void __init__();
	void  async_update();
	void __init__();
	void available();
	void device_class();
	void device_state_attributes();
	void device_info();
	void name();
	void should_poll();
	void unique_id();
	void  _update_bridge_id();
	void  async_added_to_hass();
	void update();
	void  async_will_remove_from_hass();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif