/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SENTRY_H
#define SENTRY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class sentry : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "sentry.json");
    Q_INTERFACES(HyPluginInterface);
public:
    sentry();
    ~sentry();

    QString name() 		{ return "sentry"; }
    QString description()	{ return "The sentry integration."; }

protected:
    	void  async_setup();
	void  async_setup_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif