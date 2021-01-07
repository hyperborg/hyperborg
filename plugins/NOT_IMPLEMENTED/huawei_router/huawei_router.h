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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class huawei_router : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "huawei_router.json");
    Q_INTERFACES(HyPluginInterface);
public:
    huawei_router(QObject *parent=nullptr);
    ~huawei_router();

    QString name() 		{ return "huawei_router"; }
    QString description()	{ return "The huawei_router component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif