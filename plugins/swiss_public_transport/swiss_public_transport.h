/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SWISS_PUBLIC_TRANSPORT_H
#define SWISS_PUBLIC_TRANSPORT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class swiss_public_transport : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "swiss_public_transport.json");
    Q_INTERFACES(HyPluginInterface);
public:
    swiss_public_transport();
    ~swiss_public_transport();

    QString name() 		{ return "swiss_public_transport"; }
    QString description()	{ return "The swiss_public_transport component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif