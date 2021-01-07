/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef BT_SMARTHUB_H
#define BT_SMARTHUB_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class bt_smarthub : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "bt_smarthub.json");
    Q_INTERFACES(HyPluginInterface);
public:
    bt_smarthub(QObject *parent=nullptr);
    ~bt_smarthub();

    QString name() 		{ return "bt_smarthub"; }
    QString description()	{ return "The bt_smarthub component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif