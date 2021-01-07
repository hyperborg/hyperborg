/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef UNIFI_DIRECT_H
#define UNIFI_DIRECT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class unifi_direct : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "unifi_direct.json");
    Q_INTERFACES(HyPluginInterface);
public:
    unifi_direct(QObject *parent=nullptr);
    ~unifi_direct();

    QString name() 		{ return "unifi_direct"; }
    QString description()	{ return "The unifi_direct component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif