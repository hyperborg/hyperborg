/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NEURIO_ENERGY_H
#define NEURIO_ENERGY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class neurio_energy : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "neurio_energy.json");
    Q_INTERFACES(HyPluginInterface);
public:
    neurio_energy(QObject *parent=nullptr);
    ~neurio_energy();

    QString name() 		{ return "neurio_energy"; }
    QString description()	{ return "The neurio_energy component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif