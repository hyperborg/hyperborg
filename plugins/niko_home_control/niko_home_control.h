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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class niko_home_control : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "niko_home_control.json");
    Q_INTERFACES(HyPluginInterface);
public:
    niko_home_control(QObject *parent=nullptr);
    ~niko_home_control();

    QString name() 		{ return "niko_home_control"; }
    QString description()	{ return "The niko_home_control component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif