/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef IGN_SISMOLOGIA_H
#define IGN_SISMOLOGIA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class ign_sismologia : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ign_sismologia.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ign_sismologia(QObject *parent=nullptr);
    ~ign_sismologia();

    QString name() 		{ return "ign_sismologia"; }
    QString description()	{ return "The ign_sismologia component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif