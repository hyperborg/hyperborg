/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NMAP_TRACKER_H
#define NMAP_TRACKER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class nmap_tracker : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "nmap_tracker.json");
    Q_INTERFACES(HyPluginInterface);
public:
    nmap_tracker(QObject *parent=nullptr);
    ~nmap_tracker();

    QString name() 		{ return "nmap_tracker"; }
    QString description()	{ return "The nmap_tracker component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif