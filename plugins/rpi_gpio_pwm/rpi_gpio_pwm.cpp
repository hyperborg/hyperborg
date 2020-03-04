#include <rpi_gpio_pwm.h>

rpi_gpio_pwm::rpi_gpio_pwm()
{
    	manifest.insert("domain","rpi_gpio_pwm");
	manifest.insert("name","pigpio Daemon PWM LED");
}

rpi_gpio_pwm::~rpi_gpio_pwm()
{
}


