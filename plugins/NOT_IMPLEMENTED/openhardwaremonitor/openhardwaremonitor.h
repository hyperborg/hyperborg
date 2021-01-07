/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef OPENHARDWAREMONITOR_H
#define OPENHARDWAREMONITOR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class openhardwaremonitor : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "openhardwaremonitor.json");
    Q_INTERFACES(HyPluginInterface);
public:
    openhardwaremonitor(QObject *parent=nullptr);
    ~openhardwaremonitor();

    QString name() 		{ return "openhardwaremonitor"; }
    QString description()	{ return "The openhardwaremonitor component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif