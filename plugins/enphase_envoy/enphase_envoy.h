/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ENPHASE_ENVOY_H
#define ENPHASE_ENVOY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class enphase_envoy : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "enphase_envoy.json");
    Q_INTERFACES(HyPluginInterface);
public:
    enphase_envoy();
    ~enphase_envoy();

    QString name() 		{ return "enphase_envoy"; }
    QString description()	{ return "The enphase_envoy component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif