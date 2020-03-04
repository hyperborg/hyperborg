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

class neurio_energy : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "neurio_energy.json");
    Q_INTERFACES(HyPluginInterface);
public:
    neurio_energy();
    ~neurio_energy();

    QString name() 		{ return "neurio_energy"; }
    QString description()	{ return "The neurio_energy component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif