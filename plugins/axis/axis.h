/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef AXIS_H
#define AXIS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class axis : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "axis.json");
    Q_INTERFACES(HyPluginInterface);
public:
    axis();
    ~axis();

    QString name() 		{ return "axis"; }
    QString description()	{ return "Support for Axis devices."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void async_populate_options();
	void async_migrate_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif