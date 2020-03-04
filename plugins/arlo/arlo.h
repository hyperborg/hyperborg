/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ARLO_H
#define ARLO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class arlo : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "arlo.json");
    Q_INTERFACES(HyPluginInterface);
public:
    arlo();
    ~arlo();

    QString name() 		{ return "arlo"; }
    QString description()	{ return "Support for Netgear Arlo IP cameras."; }

protected:
    	void setup();
	void hub_refresh();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif