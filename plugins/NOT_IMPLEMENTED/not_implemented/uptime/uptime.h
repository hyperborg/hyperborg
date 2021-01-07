/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef UPTIME_H
#define UPTIME_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class uptime : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "uptime.json");
    Q_INTERFACES(HyPluginInterface);
public:
    uptime(QObject *parent=nullptr);
    ~uptime();

    QString name() 		{ return "uptime"; }
    QString description()	{ return "The uptime component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif