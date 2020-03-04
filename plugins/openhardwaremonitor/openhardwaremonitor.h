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

class openhardwaremonitor : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "openhardwaremonitor.json");
    Q_INTERFACES(HyPluginInterface);
public:
    openhardwaremonitor();
    ~openhardwaremonitor();

    QString name() 		{ return "openhardwaremonitor"; }
    QString description()	{ return "The openhardwaremonitor component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif