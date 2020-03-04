/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef METEOALARM_H
#define METEOALARM_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class meteoalarm : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "meteoalarm.json");
    Q_INTERFACES(HyPluginInterface);
public:
    meteoalarm();
    ~meteoalarm();

    QString name() 		{ return "meteoalarm"; }
    QString description()	{ return "The meteoalarm component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif