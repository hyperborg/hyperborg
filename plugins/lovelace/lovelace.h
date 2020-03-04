/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LOVELACE_H
#define LOVELACE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class lovelace : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "lovelace.json");
    Q_INTERFACES(HyPluginInterface);
public:
    lovelace();
    ~lovelace();

    QString name() 		{ return "lovelace"; }
    QString description()	{ return "Support for the Lovelace UI."; }

protected:
    	void async_setup();
	void storage_dashboard_changed();
	void system_health_info();
	void _register_panel();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif