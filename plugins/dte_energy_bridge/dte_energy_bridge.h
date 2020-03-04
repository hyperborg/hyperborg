/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DTE_ENERGY_BRIDGE_H
#define DTE_ENERGY_BRIDGE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class dte_energy_bridge : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "dte_energy_bridge.json");
    Q_INTERFACES(HyPluginInterface);
public:
    dte_energy_bridge();
    ~dte_energy_bridge();

    QString name() 		{ return "dte_energy_bridge"; }
    QString description()	{ return "The dte_energy_bridge component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif