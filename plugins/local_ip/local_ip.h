/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LOCAL_IP_H
#define LOCAL_IP_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class local_ip : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "local_ip.json");
    Q_INTERFACES(HyPluginInterface);
public:
    local_ip();
    ~local_ip();

    QString name() 		{ return "local_ip"; }
    QString description()	{ return "Get the local IP address of the Home Assistant instance."; }

protected:
    	void  async_setup();
	void  async_setup_entry();
	void  async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif