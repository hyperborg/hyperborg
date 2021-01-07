#include <rpi_gpio_pwm.h>

rpi_gpio_pwm::rpi_gpio_pwm(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","pigpio Daemon PWM LED");
	manifest.insert("domain","rpi_gpio_pwm");
}

rpi_gpio_pwm::~rpi_gpio_pwm()
{
}

void rpi_gpio_pwm::init()
{
}


