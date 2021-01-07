#include <onewire.h>

onewire::onewire(QObject *parent) : HyObject(parent)
{
    basedir = "/disks/1wire/bus.0";
}

onewire::~onewire()
{
}

QJsonObject onewire::configurationTemplate()
{
    QJsonObject obj;
    return obj;
}

void onewire::saveConfiguration(QJsonObject &json)
{
    Q_UNUSED(json);
}

bool onewire::loadConfiguration(QJsonObject &json)
{
    Q_UNUSED(json);
    return true;
}

void onewire::init()
{
    scanDevices();
}

void onewire::scanDevices()
{
    qDebug() << "OneWire -- scanDevices";
    QDir dir(basedir);
    QStringList dirs = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    for (int i=0;i<dirs.count();i++)
    {
	QString id = dirs.at(i);
	qDebug() << "checking: " << id;
	QString ftype = basedir+"/"+id+"/type";
	QFileInfo fi(ftype);
	if (fi.exists())
	{
	    QFile ts(ftype);
	    if (ts.open(QIODevice::ReadOnly))
	    {
		QString tsc = QString(ts.readAll());
		tsc=tsc.simplified().toUpper();
		ts.close();
	        qDebug() << "DECIVE " << ftype << " found with type: " << ftype << " having value: " << readValue(id, ATTR_TEMPERATURE);
	    }
	}
    }
}

double onewire::readValue(QString id, int param)
{
    // lookup device parameter - this should be from some internal cache
    // but for now we directly reading this out from the owfs

    int retval = -1;
    QString ftype = basedir+"/"+id+"/type";
    qDebug() << "FTYPE: " << ftype;
    QFileInfo fi(ftype);
    if (fi.exists())
    {
        QFile ts(ftype);
        if (ts.open(QIODevice::ReadOnly))
        {
    	    QString tsc = QString(ts.readAll());
	    tsc=tsc.simplified().toUpper();
	    ts.close();

	    QString tfilename;
	    if (tsc=="DS18B20")
	    {
		switch(param)
		{
		    case ATTR_TEMPERATURE_9:  tfilename="temperature9";  break;
		    case ATTR_TEMPERATURE_10: tfilename="temperature10"; break;
		    case ATTR_TEMPERATURE_11: tfilename="temperature11"; break;
		    case ATTR_TEMPERATURE_12: tfilename="temperature12"; break;
		}
	    }

	    if (!tfilename.isEmpty())
	    {
		QFile af(basedir+"/"+id+"/"+tfilename);
		if (af.open(QIODevice::ReadOnly))
		{
		    QString val = QString(af.readAll());
		    val = val.simplified();
		    retval = val.toDouble();
		}
	    }
	}
    }
    return retval;
}

void onewire::writeValue(QString id)
{
    Q_UNUSED(id);
}
