/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HONEYWELL_H
#define HONEYWELL_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class honeywell : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "honeywell.json");
    Q_INTERFACES(HyPluginInterface);
public:
    honeywell(QObject *parent=nullptr);
    ~honeywell();

    QString name() 		{ return "honeywell"; }
    QString description()	{ return "Support for Honeywell (US) Total Connect Comfort climate systems."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif