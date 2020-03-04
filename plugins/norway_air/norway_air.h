/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NORWAY_AIR_H
#define NORWAY_AIR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class norway_air : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "norway_air.json");
    Q_INTERFACES(HyPluginInterface);
public:
    norway_air();
    ~norway_air();

    QString name() 		{ return "norway_air"; }
    QString description()	{ return "The norway_air component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif