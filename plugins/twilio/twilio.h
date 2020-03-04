/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TWILIO_H
#define TWILIO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class twilio : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "twilio.json");
    Q_INTERFACES(HyPluginInterface);
public:
    twilio();
    ~twilio();

    QString name() 		{ return "twilio"; }
    QString description()	{ return "Support for Twilio."; }

protected:
    	void  async_setup();
	void  handle_webhook();
	void  async_setup_entry();
	void  async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif