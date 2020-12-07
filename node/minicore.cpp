#include "minicore.h"

MiniCore::MiniCore(QObject* parent) : QObject(parent)
{
	// Global initialization
	query = NULL;
	readSettings();

	// setting up SQL database
	if (!connectToDatabase())
	{
	    qDebug() << "Minicore: DB is NOT connected";
	}

	// setting up Paradox
	paradox = new Paradox(this);
	QObject::connect(paradox, SIGNAL(zoneStatusChanged(int, int, int)), this, SLOT(zoneStatusChanged(int, int, int)));

	// setting up I2C
	hyi2c = new HYI2C(this);
	hyi2c->init();
	QObject::connect(hyi2c, SIGNAL(valueChanged(int, int, int)), this, SLOT(i2cValueChanged(int, int, int)));

	// setting up 1wire
	tempindex = 0;
	wiredir = "/disks/1wire";
	temp_readDelay = 5 * 1000; // 5 sec between the sensors
	temp_readFreq = 60 * 1000;	// 1 minute between sensor array readings

	// setting up timing
	QObject::connect(&temptimer, SIGNAL(timeout()), this, SLOT(readTemperatures()));
	QObject::connect(&i2ctimer, SIGNAL(timeout()), this, SLOT(readI2C()));

	temptimer.setSingleShot(false);
	temptimer.start(60 * 1000);	// read out temperatures in every minute

	i2ctimer.setSingleShot(true); // will restart from ::readI2C
	i2ctimer.start(100);
}

MiniCore::~MiniCore()
{
	if (query) delete(query);
	QSqlDatabase::removeDatabase("HNODE");
	for (int i=0;i<tempsensors.count();i++) delete(tempsensors.at(i));
	for (int i=0;i<i2citems.count();i++) delete(i2citems.at(i));
	for (int i=0;i<i2cconnects.count();i++) delete(i2cconnects.at(i));
}

void MiniCore::readSettings()
{
	QString inifile = "/home/pi/minicore.ini";
#ifdef _MSC_VER
	inifile = "c:\\projects\\minicore.ini";
#endif
	QFile f(inifile);
	if (f.open(QIODevice::ReadOnly))
	{
	    QString all = QString(f.readAll());
	    QStringList lines = all.split("\n");
	    for (int ii=0;ii<lines.count();ii++)
		{
			QString line = lines.at(ii);
			int hm = line.indexOf("#");
			if (hm > -1) line = line.mid(0, hm);	// Truncate hashmarked parts
			line = line.simplified();
			if (!line.isEmpty())
			{
				QStringList lst = line.split(",");
				int lc = lst.count();
				if (lc > 0)
				{
					QString cmd = lst.at(0).toUpper();
					if (cmd == "DB" && lc == 3)
					{
					    dbinfos.insert(lst.at(1), lst.at(2));
					}
					else if (cmd == "1WIRE" && lc == 4)
					{
					    TempSensor* ts = new TempSensor();
					    ts->file = wiredir+"/"+lst.at(1)+"/temperature9";
					    ts->title = lst.at(2);
					    ts->dbfield = lst.at(3);
					}
					else if (cmd == "I2C" && lc==5)
					{
					    I2CItem *item = new I2CItem();
					    i2citems.append(item);
					    item->name = lst.at(1); // name
					    item->bus  = lst.at(2).toInt();
					    item->bank = lst.at(3).toInt();
					    item->bit  = lst.at(4).toInt();
					}
					else if (cmd == "CONNECT" && lc == 3)
					{
					    I2CConnect *i2cc=new I2CConnect();
					    i2cconnects.append(i2cc);
					    i2cc->source=lst.at(1);
					    i2cc->target=lst.at(2);
					}
				}
			}
		}
		f.close();
	}
	else qDebug() << "Cannot open inifile: " << inifile;
}

bool MiniCore::connectToDatabase()
{
	bool retval = false;
	db = QSqlDatabase::addDatabase(dbinfos.value("DBTYPE"), "HNODE");
	db.setHostName(dbinfos.value("HOST"));
	db.setDatabaseName(dbinfos.value("DBNAME"));
	db.setUserName(dbinfos.value("DBUSER"));
	db.setPassword(dbinfos.value("PASSWORD"));
	if (db.open())
	{
		query = new QSqlQuery(db);
		retval = true;
	}
	return retval;
}

void MiniCore::readTemperatures()
{
	tempindex = qBound(0, tempindex, tempsensors.count() - 1);
	TempSensor* acts = tempsensors.at(tempindex);
	if (acts)
	{
		QFile f(acts->file);
		if (f.open(QIODevice::ReadOnly))
		{
			acts->lastval = QString(f.readAll());
			f.close();
		}
	}
	tempindex++;
	if (tempindex >= tempsensors.count())
	{
		tempindex = 0;
		temptimer.start(temp_readFreq);
		// dump all current values into SQL
		// generate SQL string now, without any precached string
	}
	else
	{
		temptimer.start(temp_readDelay);
	}
}

void MiniCore::readI2C()
{
	i2ctimer.start(100);
}

int MiniCore::setBit(int source, int idx, int newval)
{
    if (newval)		// setting bit at position idx to 1
    {
	source |= 1UL << idx;
    }
    else		// clearing a bit at position idx (set it to 0)
    {
	source &= ~(1UL << idx);
    }
    return source;
}

int MiniCore::getBit(int source, int idx)
{
    return (source >> idx) & 1U;
}

int MiniCore::toggleBit(int source, int idx)
{
    source ^= 1UL << idx;
    return source;
}

void MiniCore::zoneStatusChanged(int group, int area, int zone)
{
    qDebug() << "Minicore::zoneStatusChanged " << group << " " << area << " " << zone;
}


// This is a very simple implementation of connecting two I2C bits together. 
// It would be nice to use hashes, but for now it is fine
// It does not check against loops, so it is possible to create a source and a target
// from the same bank resulting and endless loop.
// This approach also enables 1-n connection when changing one bit in an I2C bank
// triggers changing multiple bits in different I2C banks.

// This part of MiniCore is aiming to support an I2C setup where physical swithes 
// are connected to I2C optos and their state are copied to I2C based relays.

void MiniCore::i2cValueChanged(int bus, int bank, int value)
{
    for (int i=0;i<i2citems.count();i++)
    {
	I2CItem *item = i2citems.at(i);
	if (item->bus == bus && item->bank == bank)
	{
	    int cval = getBit(value, item->bit);
	    if (cval != item->val)	// item related bit has been changed
	    {
		item->val = cval;
		for (int j=0;j<i2cconnects.count();j++)
		{
		    if (item->name==i2cconnects.at(j)->source)
		    {
			QString tname = i2cconnects.at(j)->target;
			for (int k=0;k<i2citems.count();i++)
			{
			    if (i2citems.at(k)->name==tname)
			    {
				I2CItem *titem = i2citems.at(k);
				int nb = setBit(titem->bank, titem->bit, cval);
				hyi2c->setValue(titem->bus, titem->bank, nb);
			    }
			}
		    }
		}
	    }
	}
    }

}


