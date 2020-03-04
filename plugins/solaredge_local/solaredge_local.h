/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SOLAREDGE_LOCAL_H
#define SOLAREDGE_LOCAL_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class solaredge_local : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "solaredge_local.json");
    Q_INTERFACES(HyPluginInterface);
public:
    solaredge_local();
    ~solaredge_local();

    QString name() 		{ return "solaredge_local"; }
    QString description()	{ return "The SolarEdge Local Integration."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif