#include "slotter.h"

Slotter::Slotter(QObject* parent) : QThread(parent)
{
	waitcondition = new QWaitCondition();
	slotter_mutex = new QMutex();
}

Slotter::~Slotter()
{}

void Slotter::init()
{
	// bandwidth testing
	/*
	testtimer = new QTimer();
	testtimer->setSingleShot(true);
	QObject::connect(testtimer, SIGNAL(timeout()), this, SLOT(runTest()));
	*/
//	testtimer->start(1000);
}

void Slotter::log(int severity, QString line)
{
	emit logLine(severity, line);
}

void Slotter::run()
{
/*
	forever
	{
		slotter_mutex->lock();
		waitcondition->wait(slotter_mutex, 2000);
		int pp = 1;
		while (pp)
		{
			pp = 0;
			pp += processPackFromUniCore();
		}
		slotter_mutex->unlock();
	}
	*/
}

void Slotter::runTest()
{
	log(0, "SLOTTER RUNTEST START");
	emit newPackReady(new DataPack());
}

int Slotter::processPackFromUniCore()
{
	DataPack* pack = inbound_buffer->takeFirst();
	if (!pack) return 0;
	// TESTING -- simply turn back the pack
	// emit newPackReady(pack);
	return 1;
}

void Slotter::registerEntity(Entity* entity)
{
	eslots.append(entity);
}

void Slotter::unregisterEntity(Entity* entity)
{
	eslots.removeAll(entity);
}
