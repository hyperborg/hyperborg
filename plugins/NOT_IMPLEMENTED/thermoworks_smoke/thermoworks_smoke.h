/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef THERMOWORKS_SMOKE_H
#define THERMOWORKS_SMOKE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class thermoworks_smoke : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "thermoworks_smoke.json");
    Q_INTERFACES(HyPluginInterface);
public:
    thermoworks_smoke(QObject *parent=nullptr);
    ~thermoworks_smoke();

    QString name() 		{ return "thermoworks_smoke"; }
    QString description()	{ return "The thermoworks_smoke component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif