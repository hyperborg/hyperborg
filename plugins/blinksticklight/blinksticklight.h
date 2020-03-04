/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef BLINKSTICKLIGHT_H
#define BLINKSTICKLIGHT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class blinksticklight : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "blinksticklight.json");
    Q_INTERFACES(HyPluginInterface);
public:
    blinksticklight();
    ~blinksticklight();

    QString name() 		{ return "blinksticklight"; }
    QString description()	{ return "The blinksticklight component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif