#include <unicore.h>

UniCore::UniCore(QObject *parent) : QThread(parent), bypass(true)
{
}

UniCore::~UniCore()
{
}

void UniCore::init()
{
	id_mutex = new QMutex();
	od_mutex = new QMutex();
	waitcondition = new QWaitCondition();
}

DataBlock* UniCore::getOutgoingData()
{
	QMutexLocker locker(od_mutex);
	DataBlock* rb = NULL;
	if (od_buffer.count())
	{
		rb=od_buffer.takeFirst();
	}
	return rb;
}

void UniCore::log(int severity, QString line)
{
	emit logLine(severity, line);
}

void UniCore::setRole(NodeCoreInfo info)
{
	if (info.noderole == NR_MASTER)
	{
		bypass = false;
	}
}

void UniCore::run()
{
	log(0, QString("UniCore thread started with thradId: %1").arg((int)QThread::currentThreadId()));;
	forever
	{

	}
}

void UniCore::incomingData(DataBlock* datablock)
{
	QMutexLocker locker(id_mutex);
	id_buffer.append(datablock);
	waitcondition->wakeAll();
}

void UniCore::processIncomingHEvent()
{
	id_mutex->lock();
	DataBlock* datablock = NULL;
	if (id_buffer.count())
	{
		datablock = id_buffer.takeFirst();
	}
	id_mutex->unlock();
	if (!datablock) return;

	//This is the first point outside data packet is being processed
	// WE DO NOT TRUST ANYTHING AT THIS POINT!!!
	// Before we let any packages into the main processing parts, we need to
	// check each of them for diffent attributes. If any of the next functions return false
	// we silently discard the package (with a minimal log)
	// Any malformed block should not leave this function
	// We also need to implement an input pool for the thread execution

	int errcnt = 0;
	if (!checkIntegrity(datablock))      errcnt += 1;
	else if (!checkACL(datablock))		 errcnt += 2;
	else if (!checkWhatever(datablock))  errcnt += 4;
	else if (!parseDataBlock(datablock)) errcnt += 8;
	if (errcnt)
	{
		log(1, QString("malformed incoming datablock from %1 having issue: %2").arg(datablock->socketid).arg(errcnt));
		delete(datablock);
		return;
	}
}

bool UniCore::checkIntegrity(DataBlock* db)
{
	return true;
}

bool UniCore::checkACL(DataBlock *db)
{
	return true;
}

bool UniCore::checkWhatever(DataBlock* db)
{
	return true;
}

bool UniCore::parseDataBlock(DataBlock* db)
{
	return true;
}

bool UniCore::constructDataBlock(DataBlock* db)
{
	return true;
}