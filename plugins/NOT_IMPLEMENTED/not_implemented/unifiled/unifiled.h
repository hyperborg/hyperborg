/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef UNIFILED_H
#define UNIFILED_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class unifiled : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "unifiled.json");
    Q_INTERFACES(HyPluginInterface);
public:
    unifiled(QObject *parent=nullptr);
    ~unifiled();

    QString name() 		{ return "unifiled"; }
    QString description()	{ return "Unifi LED Lights integration."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif