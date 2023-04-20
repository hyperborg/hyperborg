#include <unicore.h>

//UniCore::UniCore(HFS *_hfs, HSM *_hsm, QObject *parent) : QThread(parent), bypass(true), hfs(_hfs), hsm(_hsm)
UniCore::UniCore(HFS *_hfs, QObject *parent) : QThread(parent), bypass(true), hfs(_hfs)
{
    unicore_mutex = new QMutex();
    waitcondition = new QWaitCondition();
    hfs->subscribe(this, Bootup_NodeRole, "setElementProperty", "NODEROLE");
	if (hfs->data(Bootup_NodeRole).toString().toLower()==NR_MASTER)
	{
		bypass = false;
	}
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
    hfs->log(severity, line, "UNICORE");
}

void UniCore::setElementProperty(QString path, QVariant var)
{
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
	DataPack* DataPack = NULL;
	DataPack = databuffer->takeFirst();
	if (!DataPack) return 0;
//	log(Info, "UC: processDataFromCoreServer");
	//This is the first point outside data packet is being processed
	// WE DO NOT TRUST ANYTHING AT THIS POINT!!!
	// Before we let any packages into the main processing parts, we need to
	// check each of them for diffent attributes. If any of the next functions return false
	// we silently discard the package (with a minimal log)
	// Any malformed block should not leave this function
	// We also need to implement an input pool for the thread execution

	int errcnt = 0;
	if (!checkIntegrity(DataPack))				errcnt += 1;
	else if (!checkACL(DataPack))				errcnt += 2;
	else if (!checkWhatever(DataPack))			errcnt += 4;
	else if (!DataPack::deserialize(DataPack))		errcnt += 8;
	else if (!processDataPack(DataPack, false))	errcnt += 16;
	if (errcnt)
	{
		log(1, QString("malformed incoming DataPack from %1 having issue: %2").arg(DataPack->socketId()).arg(errcnt));
		delete(DataPack);
		return 1; // we processed DataPack. returning 0 here might stall processing for inbound
	}

	// TESTING -- simply drop DataPack and pass a new datapacked to upper layer
	return 1;
}

bool UniCore::checkIntegrity(DataPack* db)
{
	return true;
}

bool UniCore::checkACL(DataPack *db)
{
	return true;
}

bool UniCore::checkWhatever(DataPack* db)
{
	return true;
}

bool UniCore::parseDataPack(DataPack* db)
{
	return true;
}

bool UniCore::constructDataPack(DataPack* db)
{
	return true;
}

/*
    Serializatin is where we flatten all known information into a binary or textual representation
    so it could be easily sent over the socket. No other part knows about the serialization, so it 
    could define the protocol on its own. Of course serialize() and deserialize() should use the same 
    protocol. Here it is possible to introduce versions, compressions or anything, this part is hidden from
    any other part of the node.

    NOTE: For now we just create a simple name=value list delimited by \n. It is sufficient for the POC.
    If tree-line data structures are required, this should be updated as well as DataPack structures.
    Wish we are there ... :)
*/


/* ===================================================================================
				    EXECUTE DATAPACK BLOCK
======================================================================================*/

int UniCore::processPackFromSlotter()
{
	DataPack* pack = NULL;
	pack = packbuffer->takeFirst();
	if (!pack) return 0;
	processDataPack(pack, true);
	return 1;
}

bool UniCore::processDataPack(DataPack *pack, bool down)
{
	if (!pack) return false;
	if (pack->source()=="HFS" && bypass)				// We are SLAVE and all HFS related events should be transferred directly
	{													// to the MASTER. 
			emit newPackReadyForCS(pack);
			return true;
	}

    if (bypass)							// We are SLAVE. Simply passing packet to the next layer.
    {									// When decentralised execution is implemented, this is where
                                  		// we should decide wherher incoming package processed locally or not.
		if (down)
		{
			emit newPackReadyForCS(pack); 	// sending to CoreServer for dispatch
		}
		else
		{
			emit newPackReadyForSL(pack);	    // sending to Slotter
		}
    }
    else				// We are MASTER, so we need to inspect/update the package here
    {					// When done, we send out 2 packages: one for out Slotter for 
						// processing and 1 for Coreserver for dispatch

						// !!! Currently we do not modfy the package, since we are testing the package redistribution
						// among nodes

						// POC SETUP - Modify here if you want to connect actions with actors.
						// THe POC (Poof of concept) is a current test setup in the Hyperborg HQ.
						// This part of the code would be replaced later with a RedNode/Scratch like interface

		switch (pack->command())
		{
			case CommandNotDefined:
				break;
			case NOP:
				break;
			case Ping:
				break;
			case RegisterEntity:
				break;
			case UnregisterEntity:
				break;
			case SystemEvent:
				break;
			case HFSDataChangeRequest:
				{
					executeDataPack(pack, down);
				}
				break;
			case HFSSetValue:
				break;
			case HFSCreatePath:
				break;
			case HFSLog:
				break;
		}
    }
    return true;
}

void UniCore::HFS_inBound(DataPack* pack)
{
	processDataPack(pack, true);
}


/* MAGIC HAPPENS HERE */
// The codes below this point is the main logic for the system. Here we handle all incoming packets and decide what 
// to do with them. Currently this part contains mostly fixed decision paths and evaluations, but when the NodeRed/Scratch
// like interface would be kicked in, it would be handled here. 


bool UniCore::executeDataPack(DataPack* pack, bool down)
{
	//! DataPack should contain the platform in this case (datachangerequest)

	QString path = pack->attributes["path"].toString();
	QString val = pack->attributes["value"].toString();

	if (path.startsWith("button."))										// Direct control for the relay board to
	{																		// achieve wife-acceptance factor as long as
																			// the drag&drop flow editor is not implemented
		//	path = path.replace("button.", "switch.");							
		pack->attributes.insert("path", path);						// ANYTHING is requested, it is set

		pack->setCommand(PackCommands::HFSSetValue);
		pack->attributes.insert("$$REPLY", ChangeRequestReply::SetValues);
		DataPack* npack = new DataPack(pack);
		emit newPackReadyForSL(npack);
		emit newPackReadyForCS(pack);
	}
	else if (path.contains("system.time"))
	{
		hfs->setData(path, val);
	}
	else if (path == System_LogLine)
	{
		if (pack->command() == PackCommands::HFSLog)						// Only local packages have HFSLog flags set
		{																	// serialization skip coping with this flag
		}
		else
		{
			DataPack::deserialize(pack);
			val = pack->attributes["value"].toString();
		}
		hfs->directLog(val);
	}
	return true;
}



