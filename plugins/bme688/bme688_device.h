#ifndef BME688_DEVICE_H
#define BME688_DEVICE_H

#include "hdevice.h"
#include "hfs_interface.h"
#include "hfsitem.h"

class Job;

class BME688_Device : public HDevice
{
    Q_OBJECT
public:

    BME688_Device(QObject* parent = nullptr);
    ~BME688_Device();
    HyObject::Type type() { return Device; }
    void init();

public slots:

    QVariant setSamplings(Job* job);
    QVariant getTemperature(Job* job);
    QVariant getPressure(Job* job);
    QVariant getHumidity(Job* job);
    QVariant getGasResistance(Job* job);
    QVariant getIAQ(Job* job);

private:
    bool openBus();
    bool closeBus();

private:
    QString i2c_filename;                       // name of the I2C bus file, like /dev/i2c-13
    int     i2c_addr;                           // I2C register number. 
    int     file;                               // I2C bus file handler

    char    temp_sampling;                      // oversampling value of temperature
    char    hum_sampling;                       // oversampling value of humidity
    char    press_sampling;                     // oversampling value of pressure

    uint8_t tmp_a;                              // temporary variables
    uint8_t tmp_b;
    uint8_t tmp_c;
    int rv;                                     // general return value when reading/writing I2C bus

    int temp_adc;                               // raw temperature data
    double temp_comp;                           // compensated temperature data !! This is kept, since temperature is used for compensating
                                                // the calculation for humidity and pressure

    int hum_adc;                                // raw humidity data
    double hum_comp;                            // compensated humidity data

    int press_adc;                              // raw pressure data
    double press_comp;                          // compensated pressure data
};


#endif