/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SERIAL_PM_H
#define SERIAL_PM_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class serial_pm : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "serial_pm.json");
    Q_INTERFACES(HyPluginInterface);
public:
    serial_pm();
    ~serial_pm();

    QString name() 		{ return "serial_pm"; }
    QString description()	{ return "The serial_pm component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif