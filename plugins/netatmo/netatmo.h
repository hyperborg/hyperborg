/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NETATMO_H
#define NETATMO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class netatmo : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "netatmo.json");
    Q_INTERFACES(HyPluginInterface);
public:
    netatmo();
    ~netatmo();

    QString name() 		{ return "netatmo"; }
    QString description()	{ return "The Netatmo integration."; }

protected:
    	void  async_setup();
	void  async_setup_entry();
	void  async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif