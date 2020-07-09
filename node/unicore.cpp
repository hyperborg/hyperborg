#include <unicore.h>

UniCore::UniCore(QObject *parent) : QThread(parent), bypass(true)
{
#ifndef WASM
	query = NULL;
	uquery = NULL;
#endif
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
	settings = HSettings::getInstance();
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
	connectToDatabase();
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
	if (!checkIntegrity(datablock))		errcnt += 1;
	else if (!checkACL(datablock))		errcnt += 2;
	else if (!checkWhatever(datablock))	errcnt += 4;
	else if (!deserialize(datablock))	errcnt += 8;
	else if (!executeDataBlock(datablock))	errcnt += 16;
	if (errcnt)
	{
		log(1, QString("malformed incoming datablock from %1 having issue: %2").arg(datablock->socketid).arg(errcnt));
		delete(datablock);
		return 1; // we processed datablock. returning 0 here might stall processing for inbound
	}

	// TESTING -- simply drop datablock and pass a new datapacked to upper layer
	return 1;
}

int UniCore::processPackFromSlotter()
{
	DataPack* pack = NULL;
	pack = packbuffer->takeFirst();
	if (!pack) return 0;
	log(0, "UC: processPackFromSlotter");

	// This the point where we are serializing the pack
	// It might be done in CoreServer, but that might be enforced to run in foreground
	// so it is better to run in UniCore. Also CS should not know anything about the nature of 
	// the data being sent.

	if (DataBlock* block = new DataBlock())
	{
	    block->pack=pack;
	    serialize(block);
	    emit newBlockReady(block);
	    return 1;
	}
	delete(pack);
	return 0;
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

bool UniCore::executeDataBlock(DataBlock* db)
{
	if (bypass)
	{
		DataPack* datapack = new DataPack(db->pack);
		emit newPackReady(datapack);
		return true;
	}
	else
	{
		DataPack* datapack = new DataPack(db->pack);
		emit newPackReady(datapack);
		return true;
	}
	delete(db);
	return true;
}

bool UniCore::connectToDatabase()
{
#ifdef WASM
	return false;
#else
	QString db_type = settings->value(Conf_DB_Type).toString();
	QString db_host = settings->value(Conf_DB_Host).toString();
	QString db_name = settings->value(Conf_DB_Name).toString();
	QString db_user = settings->value(Conf_DB_User).toString();
	QString db_pass = settings->value(Conf_DB_Pass).toString();
	int db_port = settings->value(Conf_DB_Port).toInt();

	db = QSqlDatabase::addDatabase(db_type);
	if (!db.isValid())
	{
		log(0, "Database connection cannot be opened");
		return false;
	}

	db.setDatabaseName(db_name);
	db.setHostName(db_host);
	db.setUserName(db_user);
	db.setPassword(db_pass);
	db.setPort(db_port);

	if (db.open())
	{
		log(0, "Connected to database");
		query = new QSqlQuery(db);
		uquery = new QSqlQuery(db);
	}
	else
	{
		log(0, QString("Database error: %1").arg(db.lastError().text()));
	}

	return true;
#endif
}

void UniCore::queryTemperatureHistory()
{
#ifdef WASM
    return;
#else
    if (!query) return;

    int year  = 2017;
    int month = 1;
    QStringList retlst;	// sim
    // we might use timestamp here, just the background database is not yet converted for timestamps
    query->prepare("SELECT year, month, day, hour, min, pcs_gephaz, pcs_outside_north, pcs_living_room FROM temps_pcs WHERE year=:year, month=:month ORDER BY year, month, day, hour, min");
    query->bindValue(":year", year);
    query->bindValue(":month", month);
    if (query->exec())
    {
	while(query->next())
	{
	    QStringList llst;
	    for (int i=0;i<8;i++) llst << query->value(i).toString();
	    retlst << llst.join(",");
	}
    }
    qDebug() << " -------- FROM SQL ------ ";
    qDebug() << retlst;
    qDebug() << " ------------------------ ";
#endif
}

/*
    Serializatin is where we flatten all known information into a binary or textual representation
    so it could be easily sent over the socket. No other part knows about the serialization, so it 
    could define the protocol on its own. Of course serialize() and deserialize() should use the same 
    protocol. Here it is possible to introduce versions, compressions or anything, this part is hidden from
    any other part of the node.

    NOTE: For now we just create a simple name=value list delimited by \n. It is sufficient for the POC.
    If tree-line data structures are required, this should be updated as well as DataPack and Entity structures.
    Wish we are there ... :)
*/

int UniCore::serialize(DataBlock *block)	// we fill the the block with the sended data (binary or text)
{						// we could apply format versioning here, or compressing data
    if (!block) return 0;
    if (!block->pack)
    {
	delete(block);
	return 0;
    }

    QStringList retlst;
    QHashIterator<QString, QVariant> it(block->pack->attributes);
    while (it.hasNext())
    {
	it.next();
	retlst << QString(it.key()+"="+it.value().toString());
    }
    block->setText(retlst.join("\n"));
    return 1;
}

int UniCore::deserialize(DataBlock *block)	// we extract attributes from the text/binary data received 
{						// through socket. We could apply format versioning here or
						// decompressing data
    int retint =1;
    if (!block) return 0;
    if (block->isText)
    {
	if (!block->pack)
        {
    	    if (block->pack=new DataPack())
	    {
		QStringList lst = block->text_payload.split("\n");
		for (int i=0;i<lst.count();i++)
		{
		    QStringList wlst = lst.at(i).split("=");
		    if (wlst.count()==2)
		    {
			block->pack->attributes.insert(wlst.at(0),wlst.at(1));
		    }
		}
	    }
	}
    }
    else // binary - we do not process it yet
    {
    }
    return retint;
}

