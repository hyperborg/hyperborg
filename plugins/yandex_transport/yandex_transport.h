/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef YANDEX_TRANSPORT_H
#define YANDEX_TRANSPORT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class yandex_transport : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "yandex_transport.json");
    Q_INTERFACES(HyPluginInterface);
public:
    yandex_transport(QObject *parent=nullptr);
    ~yandex_transport();

    QString name() 		{ return "yandex_transport"; }
    QString description()	{ return "Service for obtaining information about closer bus from Transport Yandex Service."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif