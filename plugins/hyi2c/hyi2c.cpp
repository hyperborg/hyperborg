#include <hyi2c.h>
#include <sys/ioctl.h>
#include "/usr/include/linux/i2c-dev.h"

#ifndef PLATFORM_RPI
#include "/usr/include/i2c/smbus.h"
#endif

hyi2c::hyi2c(QObject *parent) : HyObject(parent)
{
}

hyi2c::~hyi2c()
{}

void hyi2c::init()
{
}

void hyi2c::scanI2CBuses()
{
    qDebug() << "Scan I2C Buses";
    QString base="/dev/";
    QStringList filterlst;
    filterlst << "i2c-*";
    QDir dir(base);
    QStringList entrylist = dir.entryList(filterlst, QDir::Files | QDir::NoDotAndDotDot);
    for (int i=0;i<entrylist.count();i++)
    {
	qDebug() << "I2C device found: " << entrylist.at(i);
    }
}

void hyi2c::scanI2CDevices(QString bus)
{
    QList<int> found;
    qDebug() << "scanI2CDevices";
    bus = "/dev/i2c-"+bus;
    QFile busf(bus);
    if (!busf.open(QIODevice::ReadOnly))
    {
	qDebug() << "Cannot open I2C bus (location: " << bus << ")";
	return;
    }

    int file = busf.handle();
    int i, res;
    for (i = 0; i < 128; ++i)
    {
	if (ioctl(file, I2C_SLAVE, i) < 0)
	{
	    if (errno == EBUSY)
	    {
		qDebug() << i << " BUSY";
		continue;
	    }
	    else
	    {
		fprintf(stderr, "Error: Could not set address to 0x%02x: %s\n", i, strerror(errno));
		return;
	    }
	}

	res = i2c_smbus_read_byte(file);
	if (res < 0)
	{
	    qDebug() << i << " --";
	    printf("-- ");
	}
	else
	{
	    qDebug() << i << " " << i;
	    found << i;
	}
    }
    busf.close();
}

int hyi2c::getHyValue(QString bus, int address)
{
    QString base = "/dev/i2c-";
    QFile busf(base+bus);
    if (!busf.open(QIODevice::ReadOnly))
    {
	qDebug() << "Cannot open I2C bus (location: " << bus << ")";
	return -1;
    }
    int file = busf.handle();
    if (ioctl(file, I2C_SLAVE, address) < 0)
    {
	qDebug() << "Cannot set slave address";
	busf.close();
	return -2;
    }
    int res = i2c_smbus_read_byte(file);
    return res;
}


void hyi2c::setHyValue(QString bus, int address, int value)
{
    QString base = "/dev/i2c-";
    QFile busf(base+bus);
    if (!busf.open(QIODevice::ReadOnly))
    {
	qDebug() << "Cannot open I2C bus (location: " << bus << ")";
	return;
    }
    int file = busf.handle();
    if (ioctl(file, I2C_SLAVE, address) < 0)
    {
	qDebug() << "Cannot set slave address";
	busf.close();
	return;
    }
     int res= i2c_smbus_write_byte(file, value);
    qDebug() << "WRITE RESULT FOR address " << address << " is " << res;
}

