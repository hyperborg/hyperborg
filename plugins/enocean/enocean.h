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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class enocean : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "enocean.json");
    Q_INTERFACES(HyPluginInterface);
public:
    enocean(QObject *parent=nullptr);
    ~enocean();

    QString name() 		{ return "enocean"; }
    QString description()	{ return "Support for EnOcean devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void __init__();
	void _send_message_callback();
	void callback();
	void async_added_to_hass();
	void _message_received_callback();
	void value_changed();
	void send_command();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif