#include <hb_i2c.h>
#include "../../node/job.h"

#include <iostream>
#include <fcntl.h>

HB_I2C::HB_I2C(QObject* parent) : HPlugin(parent), HyPluginInterface()
{
}

HB_I2C::~HB_I2C()
{}


void HB_I2C::init()
{
  int file;
  int adapter_nr = 0; /* probably dynamically determined */
  char filename[20];

  snprintf(filename, 19, "/dev/i2c-%d", adapter_nr);
  file = open(filename, O_RDWR);
  if (file < 0) {
    printf("CANNOT OPEN i2c\n");
    /* ERROR HANDLING; you can check errno to see what went wrong */
    exit(1);
  }
}
