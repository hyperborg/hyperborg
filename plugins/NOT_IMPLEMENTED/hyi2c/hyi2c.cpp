#include <hyi2c.h>

HYI2C::HYI2C(QObject *parent) : HyObject(parent)
{
    _poll_bus = 1;
    _bus_base = "/dev/i2c-";
    _pollinterval = 50;
    QObject::connect(&polltimer, SIGNAL(timeout()), this, SLOT(poll_timeout()));
}

HYI2C::~HYI2C()
{
    clearRegisters();
}

void HYI2C::init()
{
    qDebug() << "Setting up polling";
}

void HYI2C::clearRegisters()
{
    for (int i=0;i<registers.count();i++)
    {
	delete(registers.at(i));
    }
    registers.clear();
}

void HYI2C::registerPolled(int bank)
{
    PollRegister *reg = new PollRegister();
    registers.append(reg);
    reg->bank = bank;
}

void HYI2C::setPollingInterval(int interval)
{
    _pollinterval=qMax(1, interval);
    polltimer.setSingleShot(false);
}

void HYI2C::startPolling()
{
    QString tid = _bus_base+QString::number(_poll_bus);
#ifndef _MSC_VER
    _poll_fd = open(tid.toStdString().c_str(), O_RDWR);
    if (_poll_fd<0)
    {
	    qDebug() << "Cannot open I2C bus";
	    return;
    }
    polltimer.start(_pollinterval);
#endif
}

void HYI2C::stopPolling()
{
    polltimer.stop();
#ifndef _MSC_VER
    close(_poll_fd);
#endif
    _poll_fd = -1;
}

void HYI2C::poll_timeout()
{
#ifndef _MSC_VER
    char tbuff[0];
    for (int i=0;i<registers.count();i++)
    {
	    PollRegister *treg = registers.at(i);
	    if (ioctl(_poll_fd, I2C_SLAVE, treg->bank)>=0)
	    {
	        read(_poll_fd, tbuff, 1);
	        if (treg->buffer[0]!=tbuff[0])
	        {
		    emit valueChanged(treg->bus, treg->bank, (int)tbuff[0]);
	        }
	        treg->buffer[0]=tbuff[0];
	    }
    }
#endif
}

char HYI2C::getValue(int bus, int address)
{
    char res=0;
#ifndef _MSC_VER
    int l_fd = _poll_fd;
    if (l_fd==-1)
    {
	    QString tid = _bus_base+QString::number(_poll_bus);
	    l_fd = open(tid.toStdString().c_str(), O_RDWR);
	    if (l_fd<0)
	    {
	        qDebug() << "Cannot open I2C bus [2]";
	        return res;	// undefined return!
	    }
    }
    if (ioctl(l_fd, I2C_SLAVE, address) < 0) 
    {
	    printf("ioctl error[2]: %s\n", strerror(errno));
	    return res; // undefined return!
    }

    read(l_fd, &res, 1);

    if (_poll_fd==-1)	// close file handle only if polling is not using the same bus
    {
	    close(l_fd);
    }
#endif
    return res;
}

void HYI2C::setValue(int bus, int address, char value)
{
#ifndef _MSC_VER
    int l_fd = _poll_fd;
    if (l_fd==-1)
    {
	QString tid = _bus_base+QString::number(_poll_bus);
	l_fd = open(tid.toStdString().c_str(), O_RDWR);
	if (l_fd<0)
	{
	    qDebug() << "Cannot open I2C bus [2]";
	    return;
	}
    }
    if (ioctl(l_fd, I2C_SLAVE, address) < 0) 
    {
	printf("ioctl error[2]: %s\n", strerror(errno));
	return;
    }

    write(l_fd, &value, 1);

    if (_poll_fd==-1)	// close file handle only if polling is not using the same bus
    {
	close(l_fd);
    }
#endif
}

