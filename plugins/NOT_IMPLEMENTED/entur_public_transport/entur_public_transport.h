/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ENTUR_PUBLIC_TRANSPORT_H
#define ENTUR_PUBLIC_TRANSPORT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class entur_public_transport : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "entur_public_transport.json");
    Q_INTERFACES(HyPluginInterface);
public:
    entur_public_transport(QObject *parent=nullptr);
    ~entur_public_transport();

    QString name() 		{ return "entur_public_transport"; }
    QString description()	{ return "Component for integrating entur public transport."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif