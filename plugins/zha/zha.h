/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ZHA_H
#define ZHA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class zha : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "zha.json");
    Q_INTERFACES(HyPluginInterface);
public:
    zha();
    ~zha();

    QString name() 		{ return "zha"; }
    QString description()	{ return "Support for Zigbee Home Automation devices."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void _platforms_loaded();
	void async_zha_shutdown();
	void async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif