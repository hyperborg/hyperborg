/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NUKI_H
#define NUKI_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class nuki : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "nuki.json");
    Q_INTERFACES(HyPluginInterface);
public:
    nuki(QObject *parent=nullptr);
    ~nuki();

    QString name() 		{ return "nuki"; }
    QString description()	{ return "The nuki component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif