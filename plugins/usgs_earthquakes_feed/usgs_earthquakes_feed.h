/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef USGS_EARTHQUAKES_FEED_H
#define USGS_EARTHQUAKES_FEED_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class usgs_earthquakes_feed : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "usgs_earthquakes_feed.json");
    Q_INTERFACES(HyPluginInterface);
public:
    usgs_earthquakes_feed();
    ~usgs_earthquakes_feed();

    QString name() 		{ return "usgs_earthquakes_feed"; }
    QString description()	{ return "The usgs_earthquakes_feed component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif