#ifndef HYI2C_H
#define HYI2C_H

#include "common.h"
#include <hyplugin.h>
#include <hyobject.h>

#include <linux/i2c-dev.h>
#include <i2c/smbus.h>
#include "sys/ioctl.h"
#include "stdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <QString>
#include <QObject>
#include <QList>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QTimer>

class PollRegister
{
public:
    PollRegister() 
    {
        bus = -1;       // Currently we are not handling multiple I2C buses
        bank = -1;
        buffer[0]=0;
    }
    ~PollRegister() {}

    int bus;
    int bank;
    char buffer[1];
};

class HYI2C : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "hyi2c.json");
    Q_INTERFACES(HyPluginInterface);

public:
    HYI2C(QObject *parent=nullptr);
    ~HYI2C();
    int implementation() { return Developement; }
    QObject *getObject() { return this; };

    QString name() { return "HYI2C"; }
    QString description() { return "I2C Bus driver"; }

    void init();
    void setValue(int bus, int address, char value);
    char getValue(int bus, int address);

protected:
    void registerPolled(int bank);
    void clearRegisters();
    void setPollingInterval(int interval);
    void startPolling();
    void stopPolling();

signals:
    void valueChanged(int bus, int bank, int value);

private slots:
    void poll_timeout();

private:
    QString _bus_base;
    int _poll_bus;				
    int _poll_fd;				// file handler for the polling
    int _pollinterval;				// pol_fd is used for setValue and getValue if they are 
    QTimer polltimer;				// targeting the same bus
    QList<PollRegister *> registers;

};


#endif