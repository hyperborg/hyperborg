/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef BT_HOME_HUB_5_H
#define BT_HOME_HUB_5_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class bt_home_hub_5 : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "bt_home_hub_5.json");
    Q_INTERFACES(HyPluginInterface);
public:
    bt_home_hub_5();
    ~bt_home_hub_5();

    QString name() 		{ return "bt_home_hub_5"; }
    QString description()	{ return "The bt_home_hub_5 component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif