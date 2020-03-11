/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ECOAL_BOILER_H
#define ECOAL_BOILER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class ecoal_boiler : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ecoal_boiler.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ecoal_boiler(QObject *parent=nullptr);
    ~ecoal_boiler();

    QString name() 		{ return "ecoal_boiler"; }
    QString description()	{ return "Support to control ecoal/esterownik.pl coal/wood boiler controller."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif