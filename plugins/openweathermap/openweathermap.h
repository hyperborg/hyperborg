/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef OPENWEATHERMAP_H
#define OPENWEATHERMAP_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class openweathermap : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "openweathermap.json");
    Q_INTERFACES(HyPluginInterface);
public:
    openweathermap();
    ~openweathermap();

    QString name() 		{ return "openweathermap"; }
    QString description()	{ return "The openweathermap component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif