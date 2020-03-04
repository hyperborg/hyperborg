/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LUTRON_CASETA_H
#define LUTRON_CASETA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class lutron_caseta : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "lutron_caseta.json");
    Q_INTERFACES(HyPluginInterface);
public:
    lutron_caseta();
    ~lutron_caseta();

    QString name() 		{ return "lutron_caseta"; }
    QString description()	{ return "Component for interacting with a Lutron Caseta system."; }

protected:
    	void async_setup();
	void __init__();
	void async_added_to_hass();
	void device_id();
	void serial();
	void unique_id();
	void device_state_attributes();
	void should_poll();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif