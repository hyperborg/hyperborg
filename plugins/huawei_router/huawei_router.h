/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HUAWEI_ROUTER_H
#define HUAWEI_ROUTER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class huawei_router : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "huawei_router.json");
    Q_INTERFACES(HyPluginInterface);
public:
    huawei_router();
    ~huawei_router();

    QString name() 		{ return "huawei_router"; }
    QString description()	{ return "The huawei_router component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif