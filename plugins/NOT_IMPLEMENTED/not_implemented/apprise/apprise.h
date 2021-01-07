/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef APPRISE_H
#define APPRISE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class apprise : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "apprise.json");
    Q_INTERFACES(HyPluginInterface);
public:
    apprise(QObject *parent=nullptr);
    ~apprise();

    QString name() 		{ return "apprise"; }
    QString description()	{ return "The apprise component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif