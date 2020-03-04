/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef UK_TRANSPORT_H
#define UK_TRANSPORT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class uk_transport : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "uk_transport.json");
    Q_INTERFACES(HyPluginInterface);
public:
    uk_transport();
    ~uk_transport();

    QString name() 		{ return "uk_transport"; }
    QString description()	{ return "The uk_transport component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif