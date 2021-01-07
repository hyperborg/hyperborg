/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TRAFIKVERKET_WEATHERSTATION_H
#define TRAFIKVERKET_WEATHERSTATION_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class trafikverket_weatherstation : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "trafikverket_weatherstation.json");
    Q_INTERFACES(HyPluginInterface);
public:
    trafikverket_weatherstation(QObject *parent=nullptr);
    ~trafikverket_weatherstation();

    QString name() 		{ return "trafikverket_weatherstation"; }
    QString description()	{ return "The trafikverket_weatherstation component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif