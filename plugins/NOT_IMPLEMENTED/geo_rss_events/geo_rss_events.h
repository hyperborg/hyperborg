/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GEO_RSS_EVENTS_H
#define GEO_RSS_EVENTS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class geo_rss_events : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "geo_rss_events.json");
    Q_INTERFACES(HyPluginInterface);
public:
    geo_rss_events(QObject *parent=nullptr);
    ~geo_rss_events();

    QString name() 		{ return "geo_rss_events"; }
    QString description()	{ return "The geo_rss_events component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif