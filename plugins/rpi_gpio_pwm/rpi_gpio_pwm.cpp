#include <rpi_gpio_pwm.h>

rpi_gpio_pwm::rpi_gpio_pwm()
{
    	manifest.insert("name","pigpio Daemon PWM LED");
	manifest.insert("domain","rpi_gpio_pwm");
}

rpi_gpio_pwm::~rpi_gpio_pwm()
{
}


