/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NIKO_HOME_CONTROL_H
#define NIKO_HOME_CONTROL_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class niko_home_control : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "niko_home_control.json");
    Q_INTERFACES(HyPluginInterface);
public:
    niko_home_control();
    ~niko_home_control();

    QString name() 		{ return "niko_home_control"; }
    QString description()	{ return "The niko_home_control component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif