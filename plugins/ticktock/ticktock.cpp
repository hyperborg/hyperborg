#include <ticktock.h>

TickTock::TickTock(QObject *parent) : HyPluginInterface(), HyObject(parent), _dayepoch(0)
{
    init();
}

TickTock::~TickTock()
{
}

void TickTock::init()
{
    timer = new QTimer();
    timer->setSingleShot(false);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(slot_timeout()));
    timer->start(1000);

    hfs->provides(this, "system.date.year",  SENSOR);
    hfs->provides(this, "system.date.month", SENSOR);
    hfs->provides(this, "system.date.day",   SENSOR);

    hfs->provides(this, "system.time.hour", SENSOR);
    hfs->provides(this, "system.time.min", SENSOR);
    hfs->provides(this, "system.time.sec", SENSOR);

    hfs->provides(this, "system.time.epoch", SENSOR);
    hfs->provides(this, "system.time.dayepoch", SENSOR);

}

void TickTock::slot_timeout()
{
    dtn = QDateTime::currentDateTime();

    // UPDATING DATE SENSORS
    if (dtn.date().year()!=dto.date().year())
    {
	hfs->dataChangeRequest("system.date.year", dtn.date().year());
    }
    if (dtn.date().month()!=dto.date().month())
    {
	hfs->dataChangeRequest("system.date.month", dtn.date().month());
    }
    if (dtn.date().day()!=dto.date().day())
    {
	hfs->dataChangeRequest("system.date.day", dtn.date().day());
    }

    // UPDATING TIME SENSORS
    if (dtn.time().hour()!=dto.time().hour())
    {
	hfs->dataChangeRequest("system.time.hour", dtn.time().hour());
    }
    if (dtn.time().minute()!=dto.time().minute())
    {
	hfs->dataChangeRequest("system.time.hour", dtn.time().minute());
    }
    if (dtn.time().second()!=dto.time().second())
    {
	hfs->dataChangeRequest("system.time.second", dtn.time().second());
    }

    int den=(int)(dtn.time().msecsSinceStartOfDay()/1000.0);
    if (den!=_dayepoch)
    {
	hfs->dataChangeRequest("system.time.dayepoch", den);
	_dayepoch = den;
    }

    int cep = QDateTime::currentSecsSinceEpoch();
    if (cep!=_epoch)
    {
	hfs->dataChangeRequest("system.time.epoch", cep);
	_epoch = cep;
    }

    dto = dtn;
}
