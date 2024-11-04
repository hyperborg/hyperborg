#include "dfr0971_device.h"
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

#define DAC_OUTRANGE uint8_t(0x01)
#define CURRENT_REG uint8_t(0x02)
#define CHANNEL_0 uint8_t(0x02)
#define CHANNEL_1 uint8_t(0x04)

DFR0971_Device::DFR0971_Device(QObject* parent) : HDevice(parent), file(-1), i2c_addr(0x5f)     // 0x5F is the default address for Gravity 0-10V
{
    channel_reg[0] = CHANNEL_0;
    channel_reg[1] = CHANNEL_1;
}

DFR0971_Device::~DFR0971_Device()
{
}

void DFR0971_Device::init()
{
}

bool DFR0971_Device::openBus()
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

bool DFR0971_Device::closeBus()
{
#if LINUX
    if (file>0)
        close(file);
    file = -1;
    return true;
#else
    return false;
#endif
}

QVariant DFR0971_Device::setDACRange(Job* job)
{
#if LINUX
    if (openBus())
    {
        uint8_t value = 0x0;
        int range = job->getAttribute("dac_range").toInt();
        range = qBound(0, range, 10);

        if (range == 10) value = 0x11;
        i2c_smbus_write_i2c_block_data(file, DAC_OUTRANGE, 1, (const uint8_t*)&value);
        closeBus();
    }
#endif
    return QVariant();
}

QVariant DFR0971_Device::setVoltage(Job* job)
{
#if LINUX
    if (openBus())
    {
        int channel = job->getAttribute("dac_channel").toInt();
        double volt = job->getAttribute("dac_voltage").toDouble();
        volt = qBound(0.0, volt, 10.0);

        uint16_t voltage = volt;  
        if (voltage > 1000) voltage = 1000;
        voltage = (uint16_t)(((double)voltage / (double)1000.0) * 4096.0);
        voltage = voltage << 4;
        i2c_smbus_write_i2c_block_data(file, channel_reg[channel], 2, (const uint8_t*)&voltage);
        closeBus();
    }
#endif
    return QVariant();
}

