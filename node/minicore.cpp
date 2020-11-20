#include "minicore.h"

MiniCore::MiniCore(QObject* parent) : QObject(parent)
{
	query = NULL;
	tempindex = 0;
	wiredir = "/disks/1wire";
	temp_readDelay = 5 * 1000; // 5 sec between the sensors
	temp_readFreq = 60 * 1000;	// 1 minute between sensor array readings
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
}

void MiniCore::readSettings()
{
	QString inifile = "/home/pi/minicore.ini";
#ifdef _MSC_VER
	inifile = "c:\\projects\\minicore.ini";
#endif
	QFile f("/home/pi/minicore.ini");
	if (f.open(QIODevice::ReadOnly))
	{
		while (f.canReadLine())
		{
			QString line = f.readLine();
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
					else if (cmd == "1WIRE" && lc == 3)
					{
						TempSensor* ts = new TempSensor();
						ts->file = wiredir+"/"+lst.at(1)+"/temperature9";
						ts->title = lst.at(2);
						ts->dbfield = lst.at(3);
					}
				}
			}
		}
		f.close();
	}
}

void MiniCore::connectToDatabase()
{
	db = QSqlDatabase::addDatabase(dbinfos.value("DBTYPE"));
	db.setHostName(dbinfos.value("HOST"));
	db.setDatabaseName(dbinfos.value("DBNAME"));
	db.setUserName(dbinfos.value("DBUSER"));
	db.setPassword(dbinfos.value("PASSWORD"));
	if (db.open())
	{
		query = new QSqlQuery(db);
	}
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