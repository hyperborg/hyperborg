/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ECOBEE_H
#define ECOBEE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class ecobee : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ecobee.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ecobee();
    ~ecobee();

    QString name() 		{ return "ecobee"; }
    QString description()	{ return "Support for ecobee."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void __init__();
	void update();
	void refresh();
	void async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif