/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ALADDIN_CONNECT_H
#define ALADDIN_CONNECT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class aladdin_connect : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "aladdin_connect.json");
    Q_INTERFACES(HyPluginInterface);
public:
    aladdin_connect();
    ~aladdin_connect();

    QString name() 		{ return "aladdin_connect"; }
    QString description()	{ return "The aladdin_connect component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif