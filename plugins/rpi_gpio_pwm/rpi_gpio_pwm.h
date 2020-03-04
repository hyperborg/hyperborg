/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RPI_GPIO_PWM_H
#define RPI_GPIO_PWM_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class rpi_gpio_pwm : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "rpi_gpio_pwm.json");
    Q_INTERFACES(HyPluginInterface);
public:
    rpi_gpio_pwm();
    ~rpi_gpio_pwm();

    QString name() 		{ return "rpi_gpio_pwm"; }
    QString description()	{ return "The rpi_gpio_pwm component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif