/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef QUANTUM_GATEWAY_H
#define QUANTUM_GATEWAY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class quantum_gateway : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "quantum_gateway.json");
    Q_INTERFACES(HyPluginInterface);
public:
    quantum_gateway();
    ~quantum_gateway();

    QString name() 		{ return "quantum_gateway"; }
    QString description()	{ return "The quantum_gateway component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif