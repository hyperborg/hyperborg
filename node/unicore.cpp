#include <unicore.h>

UniCore::UniCore(HFS *_hfs, QObject *parent) : QThread(parent), bypass(true), hfs(_hfs)
{
    unicore_mutex = new QMutex();
    waitcondition = new QWaitCondition();
    hfs->interested(this, Conf_NodeRole);
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

/*
void UniCore::setRole(NodeCoreInfo info)
{
    if (info.noderole == NR_MASTER)
    {
		_info=info;
		bypass = false;
		QJsonObject jobj;
		loadConfiguration(jobj);
    }
}
*/

void UniCore::setElementProperty(QString path, QVariant var, int col)
{
    qDebug() << "UniCore::setElementProperty " << path << " " << var;
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
//	log(0, "UC: processDataFromCoreServer");
	//This is the first point outside data packet is being processed
	// WE DO NOT TRUST ANYTHING AT THIS POINT!!!
	// Before we let any packages into the main processing parts, we need to
	// check each of them for diffent attributes. If any of the next functions return false
	// we silently discard the package (with a minimal log)
	// Any malformed block should not leave this function
	// We also need to implement an input pool for the thread execution

	int errcnt = 0;
	if (!checkIntegrity(DataPack))				errcnt += 1;
	else if (!checkACL(DataPack))					errcnt += 2;
	else if (!checkWhatever(DataPack))			errcnt += 4;
	else if (!deserialize(DataPack))				errcnt += 8;
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

int UniCore::serialize(DataPack *pack)	// we fill the the block with the sended data (binary or text)
{						// we could apply format versioning here, or compressing data
    if (!pack) return 0;

    QStringList retlst;

    // We overwrite the attributes before serialization. This way if an entity would 
    // create the same value (badly behaving), it is overwritten here
    pack->attributes.insert("$$P_ENTITY", pack->_entityid);
    pack->attributes.insert("$$P_SOURCE", pack->_source);
    pack->attributes.insert("$$P_DESTINATION", pack->_destination);

    QHashIterator<QString, QVariant> it(pack->attributes);
    while (it.hasNext())
    {
	it.next();
	retlst << QString(it.key()+"="+it.value().toString());
    }
    pack->setText(retlst.join("\n"));
    return 1;
}

int UniCore::deserialize(DataPack *pack)	// we extract attributes from the text/binary data received 
{						// through socket. We could apply format versioning here or
						// decompressing data
    int retint =1;
    if (!pack) return 0;
    if (pack->isText())
    {
		pack->attributes.clear();
		QStringList lst = pack->_text_payload.split("\n");
		for (int i = 0; i < lst.count(); i++)
		{
			QStringList wlst = lst.at(i).split("=");
			if (wlst.count() == 2)
			{
				pack->attributes.insert(wlst.at(0), wlst.at(1));
			}
		}
		// Regenerating control values from the list
		// We assume that we get package from other Unicore, not any other source
		// Anyway, it might be wise to put some checks before this point to
		// catch man-in-the-middle attacks
		pack->_entityid=pack->attributes.value("$$P_ENTITY", "").toString();
		pack->_source=pack->attributes.value("$$P_SOURCE", "").toString();
		pack->_destination=pack->attributes.value("$$P_DESTINATION", "").toString();
    }
    else // binary - we do not process it yet
    {
    }
    return retint;
}

/* ===================================================================================
					CONFIGURATION LOADING...
======================================================================================*/
/*
	Qt supports XML, JSON, SQL, raw file access  (and a lot more) for storing configuration.
	We choose JSON now, since it can represent structured data a bit better than XML.
	But there is absolute possible to represent configuration in XML or SQL also.

	NOTE: This function could be called anytime: user can refresh, reload configuration
	anytime. 
*/

bool UniCore::loadConfiguration(QJsonObject &json)
{
    log(0, "UniCore loads configuration");
	QFile f("hynode.json");
	if (f.open(QIODevice::ReadOnly))
	{
		QByteArray arr = f.readAll();
		QJsonDocument json = QJsonDocument::fromJson(arr);
		if (json.isNull()) return false;


		f.close();
	}
	return true;
}

bool UniCore::saveConfiguration(QJsonObject &json)
{
	log(0, "UniCore saves configuration");
	QJsonDocument jsondoc;

	QFile f("hynode.json");
	if (f.open(QIODevice::WriteOnly))
	{
		QTextStream stream(&f);
		stream << jsondoc.toVariant().toString();
		f.close();
	}

	return true;
}


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
    if (bypass)					// We are SLAVE. Simply passing packet to the next layer.
    {						// When decentralised execution is implemented, this is wher
                                  		// we should decide wherher incoming package processed locally or not.
		if (down)
		{
		    log(0, "SLAVE: process package down");
			emit newPackReadyForCS(pack); 	// sending to CoreServer for dispatch
		}
		else
		{
	//	    log(0, "SLAVE: process package up");
			emit newPackReadyForSL(pack);	// sending to Slotter
		}
    }
    else					// We are MASTER, so we need to inspect/update the package here
    {						// When done, we send out 2 packages: one for out Slotter for 
						// processing and 1 for Coreserver for dispatch

	// !!! Currently we do not modfy the package, since we are testing the package redistribution
	// among nodes

		pack->attributes.insert("$$REPLY", ChangeRequestReply::SetValues);
		DataPack* npack = new DataPack(pack);
		emit newPackReadyForSL(npack);

		serialize(pack);
		emit newPackReadyForCS(pack);
    }
    return true;
}


bool UniCore::executeDataPack(DataPack* pack, bool down)
{
    return false;	// Should be the vCPU implementation here!
	if (bypass)				// We are slave, just simply push down the package
	{					// to CoreServer for sending to the mesh
    	    serialize(pack);
    	    emit newPackReadyForCS(pack);
    	    return 1;
	}

	// We are MASTER, thus this is we have to take care of the the new input
	// The "logic" of the entire mesh should be implemented from here

}



