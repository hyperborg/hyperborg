/* MiniCore is a compact 1wire, I2C engine. Its primary reason is to provide minimal functionality to the
* live system as a PIC, as long as command editor and more universal processors are not implemented.
* This is used in my house, to control the temperature and lightning as long as the "big" version cannot
* replace it (thus all features are present). When that conversion takes place, this minicore would be removed or
* reused in other parts of the system.
*/

#ifndef MINICORE_H
#define MINICORE_H

#include <QString>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QObject>
#include <QTimer>
#include <QFile>
#include <QHash>
#include <QTextStream>
#include <QDebug>
#include <QByteArray>

#include "paradox.h"
#include "hyi2c.h"

class TempSensor
{
public:
	TempSensor() { lastval = "85";  }
	~TempSensor() {}

	QString title;
	QString file;
	QString lastval;
	QString dbfield;
};

class I2CItem
{
public:
    I2CItem() 
    {
	bus = -1;
	bank = -1;
	bit = 0;
	val = -1;
    }
    ~I2CItem() {}

    QString name;
    int bus;
    int bank;
    int bit;
    int val;
};

class I2CConnect
{
public:
    I2CConnect()  {}
    ~I2CConnect() {}
    
    QString source;
    QString target;
};

class MiniCore : public QObject
{
	Q_OBJECT
public:
	MiniCore(QObject* parent = NULL);
	~MiniCore();

protected:
	void readSettings();
	bool connectToDatabase();

protected slots:
	void readTemperatures();
	void readI2C();
	void zoneStatusChanged(int group, int area, int zone);
	void i2cValueChanged(int bus, int bank, int value);

private:
	int setBit(int source, int idx, int newval);
	int getBit(int source, int idx);
	int toggleBit(int source, int idx);

private:
	QTimer temptimer;
	QTimer i2ctimer;
	QHash<QString, QString> dbinfos;
	QHash<QString, QString> sensors;
	QHash<QString, int> i2c_input;
	QHash<QString, int> i2c_output;
	QSqlDatabase db;
	QSqlQuery* query;

	Paradox *paradox;
	HYI2C *hyi2c;
	QList<TempSensor *> tempsensors;
	int tempindex;

	QString wiredir;
	int temp_readDelay; // interval (s) between 2 sensor read
	int temp_readFreq;	// interval (s) between total sensors readout

	QList<I2CItem *> i2citems;
	QList<I2CConnect *> i2cconnects;
};
#endif