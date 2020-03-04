/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SNAPCAST_H
#define SNAPCAST_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class snapcast : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "snapcast.json");
    Q_INTERFACES(HyPluginInterface);
public:
    snapcast();
    ~snapcast();

    QString name() 		{ return "snapcast"; }
    QString description()	{ return "The snapcast component."; }

protected:
    	void async_setup();
	void service_handle();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif