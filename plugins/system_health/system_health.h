/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SYSTEM_HEALTH_H
#define SYSTEM_HEALTH_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class system_health : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "system_health.json");
    Q_INTERFACES(HyPluginInterface);
public:
    system_health();
    ~system_health();

    QString name() 		{ return "system_health"; }
    QString description()	{ return "Support for System health ."; }

protected:
    	void async_register_info();
	void  async_setup();
	void  _info_wrapper();
	void  handle_info();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif