/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SSDP_H
#define SSDP_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class ssdp : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ssdp.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ssdp();
    ~ssdp();

    QString name() 		{ return "ssdp"; }
    QString description()	{ return "The SSDP integration."; }

protected:
    	void  async_setup();
	void  initialize();
	void __init__();
	void  async_scan();
	void  _process_entries();
	void  _process_entry();
	void  _fetch_description();
	void info_from_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif