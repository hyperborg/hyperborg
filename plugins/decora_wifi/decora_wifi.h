/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DECORA_WIFI_H
#define DECORA_WIFI_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class decora_wifi : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "decora_wifi.json");
    Q_INTERFACES(HyPluginInterface);
public:
    decora_wifi();
    ~decora_wifi();

    QString name() 		{ return "decora_wifi"; }
    QString description()	{ return "The decora_wifi component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif