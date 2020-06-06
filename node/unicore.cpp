#include <unicore.h>

UniCore::UniCore(QObject *parent) : QThread(parent), bypass(true)
{
	unicore_mutex = new QMutex();
	waitcondition = new QWaitCondition();
}

UniCore::~UniCore()
{
	delete(unicore_mutex);
	delete(waitcondition);
}

void UniCore::init()
{
}

QWaitCondition* UniCore::getWaitCondition()
{
	return waitcondition;
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
	forever
	{
		unicore_mutex->lock();
		waitcondition->wait(unicore_mutex, 2000);
		int pp = 1;
		while(pp)
		{
			pp = 0;
			pp += processPackFromSlotter();
			pp += processDataFromCoreServer();
		}
		unicore_mutex->unlock();
	}
}

int UniCore::processDataFromCoreServer()
{
	DataBlock* datablock = NULL;
	datablock = databuffer->takeFirst();
	if (!datablock) return 0;
	log(0, "UC: processDataFromCoreServer");
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
		return 1; // we processed datablock. returning 0 here might stall processing for inbound
	}

	// TESTING -- simply drop datablock and pass a new datapacked to upper layer
	delete(datablock);
	DataPack* datapack = new DataPack();
	emit newPackReady(datapack);
	return 1;
}

int UniCore::processPackFromSlotter()
{
	DataPack* pack = NULL;
	pack = packbuffer->takeFirst();
	if (!pack)
	{
//		log(0, "NON-VALID PACK in UC");
		return 0;
	}
	log(0, "UC: processPackFromSlotter");

	// TESTING - simply drop pack and create a block and pass
	delete(pack);
	DataBlock* block = new DataBlock();
	emit newBlockReady(block);
	return 1;
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

