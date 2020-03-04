/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef WAKE_ON_LAN_H
#define WAKE_ON_LAN_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class wake_on_lan : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "wake_on_lan.json");
    Q_INTERFACES(HyPluginInterface);
public:
    wake_on_lan();
    ~wake_on_lan();

    QString name() 		{ return "wake_on_lan"; }
    QString description()	{ return "Support for sending Wake-On-LAN magic packets."; }

protected:
    	void async_setup();
	void send_magic_packet();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif