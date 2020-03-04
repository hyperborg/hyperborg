/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef UPC_CONNECT_H
#define UPC_CONNECT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class upc_connect : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "upc_connect.json");
    Q_INTERFACES(HyPluginInterface);
public:
    upc_connect();
    ~upc_connect();

    QString name() 		{ return "upc_connect"; }
    QString description()	{ return "The upc_connect component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif