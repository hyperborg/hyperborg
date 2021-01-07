/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef CPPM_TRACKER_H
#define CPPM_TRACKER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class cppm_tracker : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "cppm_tracker.json");
    Q_INTERFACES(HyPluginInterface);
public:
    cppm_tracker(QObject *parent=nullptr);
    ~cppm_tracker();

    QString name() 		{ return "cppm_tracker"; }
    QString description()	{ return "Add support for ClearPass Policy Manager."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif