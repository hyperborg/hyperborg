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

class trafikverket_weatherstation : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "trafikverket_weatherstation.json");
    Q_INTERFACES(HyPluginInterface);
public:
    trafikverket_weatherstation();
    ~trafikverket_weatherstation();

    QString name() 		{ return "trafikverket_weatherstation"; }
    QString description()	{ return "The trafikverket_weatherstation component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif