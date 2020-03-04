/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef CO2SIGNAL_H
#define CO2SIGNAL_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class co2signal : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "co2signal.json");
    Q_INTERFACES(HyPluginInterface);
public:
    co2signal();
    ~co2signal();

    QString name() 		{ return "co2signal"; }
    QString description()	{ return "The co2signal component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif