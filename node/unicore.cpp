#include <unicore.h>

UniCore::UniCore(QObject *parent) : QObject(parent)
{
}

UniCore::~UniCore()
{
}

void UniCore::init()
{
}

void UniCore::log(int severity, QString line)
{
	emit logLine(severity, line);
}

void UniCore::incomingData(DataBlock* datablock)
{
	//This is the first point outside data packet is being processed
	// WE DO NOT TRUST ANYTHING AT THIS POINT!!!
	// Before we let any packages into the main processing parts, we need to
	// check each of them for diffent attributes. If any of the next functions return false
	// we silently discard the package (with a minimal log)
	// Any malformed block should not leave this function

	int errcnt = 0;
	if (!checkIntegrity(datablock))      errcnt+=1;
	else if (!checkACL(datablock))		 errcnt+=2;
	else if (!checkWhatever(datablock))  errcnt+=4;
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

