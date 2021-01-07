/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NOAA_TIDES_H
#define NOAA_TIDES_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class noaa_tides : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "noaa_tides.json");
    Q_INTERFACES(HyPluginInterface);
public:
    noaa_tides(QObject *parent=nullptr);
    ~noaa_tides();

    QString name() 		{ return "noaa_tides"; }
    QString description()	{ return "The noaa_tides component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif