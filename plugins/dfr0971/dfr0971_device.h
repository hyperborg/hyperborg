#ifndef DFR0971_DEVICE_H
#define DFR0971_DEVICE_H

#include "hdevice.h"
#include "hfs_interface.h"
#include "hfsitem.h"

class Job;

class DFR0971_Device : public HDevice
{
    Q_OBJECT
public:
    
    DFR0971_Device(QObject* parent = nullptr);
    ~DFR0971_Device();
    HyObject::Type type() { return Device; }
    void init();

public slots:

    QVariant setDACRange(Job* job);              // setting the 0-5V or 0-10V range for all channels
    QVariant setVoltage(Job* job);              // set output voltage for a given channel

private:
    bool openBus();
    bool closeBus();

private:
    QString i2c_filename;                       // name of the I2C bus file, like /dev/i2c-13
    int     i2c_addr;                           // I2C register number. For the Gravity 010
                                                // this should be in the 0x58-0x5F range 
                                                // can be modified with the micro-dip switches on board
    int     file;                               // I2C bus file handler
    uint8_t channel_reg[2];
};

#endif