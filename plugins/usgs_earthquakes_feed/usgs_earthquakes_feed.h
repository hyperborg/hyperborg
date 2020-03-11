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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class usgs_earthquakes_feed : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "usgs_earthquakes_feed.json");
    Q_INTERFACES(HyPluginInterface);
public:
    usgs_earthquakes_feed(QObject *parent=nullptr);
    ~usgs_earthquakes_feed();

    QString name() 		{ return "usgs_earthquakes_feed"; }
    QString description()	{ return "The usgs_earthquakes_feed component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif