/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GOOGLE_WIFI_H
#define GOOGLE_WIFI_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class google_wifi : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "google_wifi.json");
    Q_INTERFACES(HyPluginInterface);
public:
    google_wifi();
    ~google_wifi();

    QString name() 		{ return "google_wifi"; }
    QString description()	{ return "The google_wifi component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif