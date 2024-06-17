#include "bme688_device.h"
#include "../../node/job.h"

#include <iostream>

#if LINUX
extern "C"
{
#include <linux/i2c-dev.h>
#include <i2c/smbus.h>
}

#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#endif


BME688_Device::BME688_Device(QObject* parent) : HDevice(parent), file(-1), i2c_addr(0x77)     // 077x is the default address for BME688
{
    setId("BME688DEV");
}

BME688_Device::~BME688_Device()
{
}

void BME688_Device::init()
{
}

bool BME688_Device::openBus()
{
#if LINUX
    file = open(filename, O_RDWR);
    if (file < 0)
    {
        // printf("cannot open device\n");
        // ERROR HANDLING; you can check errno to see what went wrong
        return false
    }

    if (ioctl(file, I2C_SLAVE, i2c_addr) < 0) {
        //printf("cannot slave\n");
        // ERROR HANDLING; you can check errno to see what went wrong
        return false;
    }
    return true;
#else
    return false;
#endif
}

bool BME688_Device::closeBus()
{
#if LINUX
    if (file > 0)
        close(file);
    file = -1;
    return true;
#else
    return false;
#endif
}

QVariant BME688_Device::setSamplings(Job* job)
{
#if LINUX
    if (openBus())
    {
        // Setting IIRS filter control - this is default here, it sets the accurancy to 20 bits 
        tmp_a = 0b00101001;
        i2c_smbus_write_i2c_block_data(file, 0x75, 1, &tmp_a);

        // Setting humidity oversampling
        tmp_a = 0b00000010;
        i2c_smbus_write_i2c_block_data(file, 0x72, 1, &tmp_a);

        // Setting temperature and pressuer oversampling and force trigger one measurement
        tmp_a = 0b01010101;
        i2c_smbus_write_i2c_block_data(file, 0x74, 1, &tmp_a);

        // !!! Note: this does not yet set run_gas, so we do not execute gas resistance 
        // sampling at this moment

        closeBus();
    }
#endif
    return QVariant();
}

QVariant BME688_Device::getTemperature(Job* job)
{
#if LINUX
    if (openBus())
    {

        // reading par_t1
        rv = i2c_smbus_read_i2c_block_data(file, 0xEA, 1, &tmp_a);
        rv = i2c_smbus_read_i2c_block_data(file, 0xE9, 1, &tmp_b);
        unsigned int par_t1 = tmp_a * 256 + tmp_b;

        // reading par_t2
        rv = i2c_smbus_read_i2c_block_data(file, 0x8B, 1, &tmp_a);
        rv = i2c_smbus_read_i2c_block_data(file, 0x8A, 1, &tmp_b);
        unsigned int par_t2 = tmp_a * 256 + tmp_b;

        // reading par_t3
        rv = i2c_smbus_read_i2c_block_data(file, 0x8C, 1, &tmp_a);
        unsigned int par_t3 = tmp_a;

        // reading temp_adc
        rv = i2c_smbus_read_i2c_block_data(file, 0x22, 1, &tmp_a);
        rv = i2c_smbus_read_i2c_block_data(file, 0x23, 1, &tmp_b);
        rv = i2c_smbus_read_i2c_block_data(file, 0x24, 1, &tmp_c);
        tmp_c = tmp_c & 0xF0;
        temp_adc = tmp_a;
        temp_adc = temp_adc << 8;
        temp_adc += tmp_b;
        temp_adc = temp_adc << 8;
        temp_adc += tmp_c;
        temp_adc = temp_adc >> 4;

        double var1 = (((double)temp_adc / 16384.0) - ((double)par_t1 / 1024.0)) * (double)par_t2;
        double var2 = ((((double)temp_adc / 131072.0) - ((double)par_t1 / 8192.0)) *
            (((double)temp_adc / 131072.0) - ((double)par_t1 / 8192.0))) *
            ((double)par_t3 * 16.0);
        double t_fine = var1 + var2;
        temp_comp = t_fine / 5120.0;

        printf("temp_comp %f\n", temp_comp);
        closeBus();
    }
#endif
    return QVariant();
}

QVariant BME688_Device::getPressure(Job* job)
{
#if LINUX
    if (openBus())
    {
        unsigned int par[11] = { 0,0,0,0,0,0,0,0,0,0,0 }; // one more for 1 based index - to conform BME688 datasheet
        // reading par_p1
        rv = i2c_smbus_read_i2c_block_data(file, 0x8F, 1, &tmp_a);
        rv = i2c_smbus_read_i2c_block_data(file, 0x8E, 1, &tmp_b);
        par[1] = tmp_a * 256 + tmp_b;

        // reading par_p2
        rv = i2c_smbus_read_i2c_block_data(file, 0x91, 1, &tmp_a);
        rv = i2c_smbus_read_i2c_block_data(file, 0x90, 1, &tmp_b);
        par[2] = tmp_a * 256 + tmp_b;

        // reading par_p3
        rv = i2c_smbus_read_i2c_block_data(file, 0x92, 1, &tmp_a);
        par[3] = tmp_a;

        // reading par_p4
        rv = i2c_smbus_read_i2c_block_data(file, 0x95, 1, &tmp_a);
        rv = i2c_smbus_read_i2c_block_data(file, 0x94, 1, &tmp_b);
        par[4] = tmp_a * 256 + tmp_b;

        // reading par_p5
        rv = i2c_smbus_read_i2c_block_data(file, 0x97, 1, &tmp_a);
        rv = i2c_smbus_read_i2c_block_data(file, 0x96, 1, &tmp_b);
        par[5] = tmp_a * 256 + tmp_b;

        // reading par_p6
        rv = i2c_smbus_read_i2c_block_data(file, 0x99, 1, &tmp_a);
        par[6] = tmp_a;

        // reading par_p7
        rv = i2c_smbus_read_i2c_block_data(file, 0x98, 1, &tmp_a);
        par[7] = tmp_a;

        // reading par_p8
        rv = i2c_smbus_read_i2c_block_data(file, 0x9D, 1, &tmp_a);
        rv = i2c_smbus_read_i2c_block_data(file, 0x9C, 1, &tmp_b);
        par[8] = tmp_a * 256 + tmp_b;

        // reading par_p9
        rv = i2c_smbus_read_i2c_block_data(file, 0x9F, 1, &tmp_a);
        rv = i2c_smbus_read_i2c_block_data(file, 0x9E, 1, &tmp_b);
        par[9] = tmp_a * 256 + tmp_b;

        // reading par_p10
        rv = i2c_smbus_read_i2c_block_data(file, 0xA0, 1, &tmp_a);
        par[10] = tmp_a;

        // reading press_adc
        rv = i2c_smbus_read_i2c_block_data(file, 0x1F, 1, &tmp_a);
        rv = i2c_smbus_read_i2c_block_data(file, 0x20, 1, &tmp_b);
        rv = i2c_smbus_read_i2c_block_data(file, 0x21, 1, &tmp_c);
        tmp_c = tmp_c & 0xF0;
        press_adc = tmp_a;
        press_adc = press_adc << 8;
        press_adc += tmp_b;
        press_adc = press_adc << 8;
        press_adc += tmp_c;
        press_adc = press_adc >> 4;

        double var1, var2, var3;
        var1 = ((double)t_fine / 2.0) - 64000.0;
        var2 = var1 * var1 * ((double)par[6] / 131072.0);
        var2 = var2 + (var1 * (double)par[5] * 2.0);
        var2 = (var2 / 4.0) + ((double)par[4] * 65536.0);
        var1 = ((((double)par[3] * var1 * var1) / 16384.0) + ((double)par[2] * var1)) / 524288.0;
        var1 = (1.0 + (var1 / 32768.0)) * (double)par[1];

        press_comp = 1048576.0 - (double)press_adc;
        press_comp = ((press_comp - (var2 / 4096.0)) * 6250.0) / var1;
        var1 = ((double)par[9] * press_comp * press_comp) / 2147483648.0;
        var2 = press_comp * ((double)par[8] / 32768.0);
        var3 = (press_comp / 256.0) * (press_comp / 256.0) * (press_comp / 256.0) * (par[10] / 131072.0);
        press_comp = press_comp + (var1 + var2 + var3 + ((double)par[7] * 128.0)) / 16.0;

        printf("press_comp %f\n", press_comp);
        closeBus();
    }
#endif
    return QVariant();
}

QVariant BME688_Device::getHumidity(Job* job)
{
#if LINUX
    if (openBus())
    {
        unsigned int h[8] = { 0,0,0,0,0,0,0,0 };  // one more for 1 based index - to conform BME688 datasheet
        double hum_comp = 0;

        // reading par_h1
        rv = i2c_smbus_read_i2c_block_data(file, 0xE3, 1, &tmp_a);
        rv = i2c_smbus_read_i2c_block_data(file, 0xE2, 1, &tmp_b);
        tmp_b = tmp_b & 0x0F;
        h[1] = tmp_a;
        h[1] = h[1] << 4;
        h[1] += tmp_b;

        // reading par_h2
        rv = i2c_smbus_read_i2c_block_data(file, 0xE1, 1, &tmp_a);
        rv = i2c_smbus_read_i2c_block_data(file, 0xE2, 1, &tmp_b);
        tmp_b = tmp_b & 0xF0;
        h[2] = tmp_a * 256 + tmp_b;
        h[2] = h[2] >> 4;

        // reading par_h3
        rv = i2c_smbus_read_i2c_block_data(file, 0xE4, 1, &tmp_a);
        h[3] = tmp_a;

        // reading par_h4
        rv = i2c_smbus_read_i2c_block_data(file, 0xE5, 1, &tmp_a);
        h[4] = tmp_a;

        // reading par_h5
        rv = i2c_smbus_read_i2c_block_data(file, 0xE6, 1, &tmp_a);
        h[5] = tmp_a;

        // reading par_h6
        rv = i2c_smbus_read_i2c_block_data(file, 0xE7, 1, &tmp_a);
        h[6] = tmp_a;

        // reading par_h7
        rv = i2c_smbus_read_i2c_block_data(file, 0xE8, 1, &tmp_a);
        h[7] = tmp_a;

        // reading hum_adc
        rv1 = i2c_smbus_read_i2c_block_data(file, 0x25, 1, &tmp_a);
        rv2 = i2c_smbus_read_i2c_block_data(file, 0x26, 1, &tmp_b);
        hum_adc = tmp_a * 256 + tmp_b;

        double var1, var2, var3, var4;
        var1 = hum_adc - (((double)h[1] * 16.0) + (((double)h[3] / 2.0) * temp_comp));
        var2 = var1 * (((double)h[2] / 262144.0) * (1.0 + (((double)h[4] / 16384.0) *
            temp_comp) + (((double)h[5] / 1048576.0) * temp_comp * temp_comp)));
        var3 = (double)h[6] / 16384.0;
        var4 = (double)h[7] / 2097152.0;

        hum_comp = var2 + ((var3 + (var4 * temp_comp)) * var2 * var2);

        printf(" hum_comp: %f\n", hum_comp);

        closeBus();
    }
#endif
    return QVariant();
}

QVariant BME688_Device::getGasResistance(Job* job)
{
#if LINUX
    if (openBus())
    {
        closeBus();
    }
#endif
    return QVariant();
}

QVariant BME688_Device::getIAQ(Job* job)
{
#if LINUX
    if (openBus())
    {
        closeBus();
    }
#endif
    return QVariant();
}

