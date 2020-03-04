/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef IAQUALINK_H
#define IAQUALINK_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class iaqualink : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "iaqualink.json");
    Q_INTERFACES(HyPluginInterface);
public:
    iaqualink();
    ~iaqualink();

    QString name() 		{ return "iaqualink"; }
    QString description()	{ return "Component to embed Aqualink devices."; }

protected:
    	void  async_setup();
	void  async_setup_entry();
	void  _async_systems_update();
	void  async_unload_entry();
	void refresh_system();
	void  wrapper();
	void __init__();
	void  async_added_to_hass();
	void _update_callback();
	void should_poll();
	void unique_id();
	void assumed_state();
	void available();
	void device_info();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif