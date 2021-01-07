/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TANK_UTILITY_H
#define TANK_UTILITY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class tank_utility : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "tank_utility.json");
    Q_INTERFACES(HyPluginInterface);
public:
    tank_utility(QObject *parent=nullptr);
    ~tank_utility();

    QString name() 		{ return "tank_utility"; }
    QString description()	{ return "The tank_utility component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif