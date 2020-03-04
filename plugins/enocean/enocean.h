/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ENOCEAN_H
#define ENOCEAN_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class enocean : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "enocean.json");
    Q_INTERFACES(HyPluginInterface);
public:
    enocean();
    ~enocean();

    QString name() 		{ return "enocean"; }
    QString description()	{ return "Support for EnOcean devices."; }

protected:
    	void setup();
	void __init__();
	void _send_message_callback();
	void callback();
	void __init__();
	void  async_added_to_hass();
	void _message_received_callback();
	void value_changed();
	void send_command();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif