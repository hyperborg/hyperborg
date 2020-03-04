/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef AMBICLIMATE_H
#define AMBICLIMATE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class ambiclimate : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ambiclimate.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ambiclimate();
    ~ambiclimate();

    QString name() 		{ return "ambiclimate"; }
    QString description()	{ return "Support for Ambiclimate devices."; }

protected:
    	void async_setup();
	void async_setup_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif