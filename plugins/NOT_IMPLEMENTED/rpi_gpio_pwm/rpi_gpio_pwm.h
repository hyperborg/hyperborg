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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class rpi_gpio_pwm : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "rpi_gpio_pwm.json");
    Q_INTERFACES(HyPluginInterface);
public:
    rpi_gpio_pwm(QObject *parent=nullptr);
    ~rpi_gpio_pwm();

    QString name() 		{ return "rpi_gpio_pwm"; }
    QString description()	{ return "The rpi_gpio_pwm component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif