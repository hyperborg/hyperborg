/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef BLUETOOTH_TRACKER_H
#define BLUETOOTH_TRACKER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class bluetooth_tracker : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "bluetooth_tracker.json");
    Q_INTERFACES(HyPluginInterface);
public:
    bluetooth_tracker();
    ~bluetooth_tracker();

    QString name() 		{ return "bluetooth_tracker"; }
    QString description()	{ return "The bluetooth_tracker component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif