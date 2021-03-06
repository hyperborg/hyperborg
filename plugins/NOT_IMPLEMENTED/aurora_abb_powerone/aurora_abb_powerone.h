/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef AURORA_ABB_POWERONE_H
#define AURORA_ABB_POWERONE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class aurora_abb_powerone : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "aurora_abb_powerone.json");
    Q_INTERFACES(HyPluginInterface);
public:
    aurora_abb_powerone(QObject *parent=nullptr);
    ~aurora_abb_powerone();

    QString name() 		{ return "aurora_abb_powerone"; }
    QString description()	{ return "The Aurora ABB Powerone PV inverter sensor integration."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif