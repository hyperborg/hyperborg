/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DYSON_H
#define DYSON_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class dyson : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "dyson.json");
    Q_INTERFACES(HyPluginInterface);
public:
    dyson();
    ~dyson();

    QString name() 		{ return "dyson"; }
    QString description()	{ return "Support for Dyson Pure Cool Link devices."; }

protected:
    	void setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif