/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef IQVIA_H
#define IQVIA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class iqvia : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "iqvia.json");
    Q_INTERFACES(HyPluginInterface);
public:
    iqvia();
    ~iqvia();

    QString name() 		{ return "iqvia"; }
    QString description()	{ return "Support for IQVIA."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void refresh();
	void async_unload_entry();
	void __init__();
	void async_update();
	void available();
	void device_state_attributes();
	void icon();
	void state();
	void unique_id();
	void unit_of_measurement();
	void async_added_to_hass();
	void update();
	void async_will_remove_from_hass();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif