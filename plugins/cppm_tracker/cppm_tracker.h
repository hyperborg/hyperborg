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

class cppm_tracker : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "cppm_tracker.json");
    Q_INTERFACES(HyPluginInterface);
public:
    cppm_tracker();
    ~cppm_tracker();

    QString name() 		{ return "cppm_tracker"; }
    QString description()	{ return "Add support for ClearPass Policy Manager."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif