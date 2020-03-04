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

class yandex_transport : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "yandex_transport.json");
    Q_INTERFACES(HyPluginInterface);
public:
    yandex_transport();
    ~yandex_transport();

    QString name() 		{ return "yandex_transport"; }
    QString description()	{ return "Service for obtaining information about closer bus from Transport Yandex Service."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif