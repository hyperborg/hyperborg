/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MAILGUN_H
#define MAILGUN_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class mailgun : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mailgun.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mailgun();
    ~mailgun();

    QString name() 		{ return "mailgun"; }
    QString description()	{ return "Support for Mailgun."; }

protected:
    	void async_setup();
	void handle_webhook();
	void verify_webhook();
	void async_setup_entry();
	void async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif