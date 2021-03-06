/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LIFX_LEGACY_H
#define LIFX_LEGACY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class lifx_legacy : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "lifx_legacy.json");
    Q_INTERFACES(HyPluginInterface);
public:
    lifx_legacy(QObject *parent=nullptr);
    ~lifx_legacy();

    QString name() 		{ return "lifx_legacy"; }
    QString description()	{ return "The lifx_legacy component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif