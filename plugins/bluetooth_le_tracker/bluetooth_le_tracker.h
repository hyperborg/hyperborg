/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef BLUETOOTH_LE_TRACKER_H
#define BLUETOOTH_LE_TRACKER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class bluetooth_le_tracker : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "bluetooth_le_tracker.json");
    Q_INTERFACES(HyPluginInterface);
public:
    bluetooth_le_tracker();
    ~bluetooth_le_tracker();

    QString name() 		{ return "bluetooth_le_tracker"; }
    QString description()	{ return "The bluetooth_le_tracker component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif