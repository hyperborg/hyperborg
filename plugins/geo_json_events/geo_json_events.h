/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GEO_JSON_EVENTS_H
#define GEO_JSON_EVENTS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class geo_json_events : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "geo_json_events.json");
    Q_INTERFACES(HyPluginInterface);
public:
    geo_json_events();
    ~geo_json_events();

    QString name() 		{ return "geo_json_events"; }
    QString description()	{ return "The geo_json_events component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif