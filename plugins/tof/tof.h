/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TOF_H
#define TOF_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class tof : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "tof.json");
    Q_INTERFACES(HyPluginInterface);
public:
    tof();
    ~tof();

    QString name() 		{ return "tof"; }
    QString description()	{ return "Platform for Time of Flight sensor VL53L1X from STMicroelectronics."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif