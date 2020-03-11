/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef FRITZBOX_CALLMONITOR_H
#define FRITZBOX_CALLMONITOR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class fritzbox_callmonitor : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "fritzbox_callmonitor.json");
    Q_INTERFACES(HyPluginInterface);
public:
    fritzbox_callmonitor(QObject *parent=nullptr);
    ~fritzbox_callmonitor();

    QString name() 		{ return "fritzbox_callmonitor"; }
    QString description()	{ return "The fritzbox_callmonitor component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif