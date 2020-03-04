/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SUEZ_WATER_H
#define SUEZ_WATER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class suez_water : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "suez_water.json");
    Q_INTERFACES(HyPluginInterface);
public:
    suez_water();
    ~suez_water();

    QString name() 		{ return "suez_water"; }
    QString description()	{ return "France Suez Water integration."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif