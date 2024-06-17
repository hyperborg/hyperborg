/* This file is moved here from HyperBorg testpad where a series of
   Gravity 010V boards were tested. All contents are intentionally commented
   out, since it is not yet compatible with HFS.
*/

/*

#include <iostream>

extern "C"
{
    #include <linux/i2c-dev.h>
    #include <i2c/smbus.h>
}

#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    printf("Hello world!");

  int file;
  int adapter_nr = 13;
  char filename[20];

  snprintf(filename, 19, "/dev/i2c-%d", adapter_nr);
  file = open(filename, O_RDWR);
  if (file < 0) {
    printf("cannot open device\n");
    // ERROR HANDLING; you can check errno to see what went wrong
    exit(1);
  }

  int addr = 0x5f; // The I2C address

  if (ioctl(file, I2C_SLAVE, addr) < 0) {
    printf("cannot slave\n");
       // ERROR HANDLING; you can check errno to see what went wrong
    exit(1);
  }

#define DAC_OUTRANGE uint8_t(0x01)
#define CURRENT_REG uint8_t(0x02)
#define CHANNEL_0 uint8_t(0x02)
#define CHANNEL_1 uint8_t(0x04)

    printf("setting 10V range\n");
    __u8 a_values[1];
    a_values[0] = 0x11; // should be 0 for 0-5V range
    i2c_smbus_write_i2c_block_data(file, DAC_OUTRANGE, 1, (const __u8*)&a_values);

    printf("setting channel 0 to ... \n");
    __u8 b_values[2];
    b_values[0]=0x00;
    b_values[1]=0x01;
    i2c_smbus_write_i2c_block_data(file, CHANNEL_0, 2, (const __u8*)&b_values);

    __uint16_t voltage = 666;   // should be 10.00V
    printf("setting channel 1 to ... %fV\n", voltage/100.0);
    if (voltage>1000) voltage = 1000;
    voltage = (__uint16_t)(((double)voltage/(double)1000.0)*4095.0);

    voltage = voltage << 4;
    i2c_smbus_write_i2c_block_data(file, CHANNEL_1, 2, (const __u8*)&voltage);

    close(file);

    return 0;
}

// CURRENT_REG 0x01 -> sets