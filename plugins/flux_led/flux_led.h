/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef FLUX_LED_H
#define FLUX_LED_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class flux_led : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "flux_led.json");
    Q_INTERFACES(HyPluginInterface);
public:
    flux_led();
    ~flux_led();

    QString name() 		{ return "flux_led"; }
    QString description()	{ return "The flux_led component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif