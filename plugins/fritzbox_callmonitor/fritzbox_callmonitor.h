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

class fritzbox_callmonitor : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "fritzbox_callmonitor.json");
    Q_INTERFACES(HyPluginInterface);
public:
    fritzbox_callmonitor();
    ~fritzbox_callmonitor();

    QString name() 		{ return "fritzbox_callmonitor"; }
    QString description()	{ return "The fritzbox_callmonitor component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif