#ifndef COMMON_H
#define COMMON_H

#include <QVariant>
#include <QString>
#include <QStringList>
#include <QList>
#include <QHash>
#include <QHashIterator>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

// HTEST is marking code parts that are there for shortcut or testing reasons
#define HTEST 1

#define NODE_RESTART_CODE 2222

const QString HYPERBORG_VERSION         = QStringLiteral("1.0.0");
const QString HYPERBORG_BUILD_TIMESTAMP = QStringLiteral(__DATE__ " " __TIME__);

class UniCore;
class CoreServer;
class Slotter;

enum PowerOptions
{
	NonCritical 	= 0,	// this is the default, we do not care if node/plugin is unplugged
				// in power failure, we are not expecting to see these nodes, thus
				// there is no waiting for communication timeout
	NeedsShutdown	= 1,	// it requires some time to properly shut down its plugins and itself
				// ex. if node contains dimmable lamps, in order to save energy and lower
				// load on aux/emergency power, it should turn all laps to 0 before
				// quitting
	KeepAlive    	= 2,	// This should be kept live at all cost
	HasUPS		= 4,	// This node/plugin has UPS power wired in (they connected to emergency power)
	PowerSave		= 8	// This node/plugin could be instructed to be in powersave mode
				// For example if there are designated plugs containing rechargeable elements
				// phone chargers, induction chargers 
};

enum SystemStates
{
	Normal		= 0,	// System is normal state (no config modification, no new nodes, no discovery,
				// failures handled mostly as warnings
	Installation	= 1,	// Config modification enabled, new units could be added, alarm surpressed 
	Alarm		= 2	// Alarm system reported alarm situation or not reacheable (all failure is
				// considered to be fatal (unit loss triggers alarm)
};

enum PluginStates
{
	Offline		= 0,	// The plugin is in a non-operable state. There is some problem or init() failed
	Disabled		= 1,	// The plugin is capable of doing something, but it does not, since it was disabled
	Online		= 2,	// Plugin is fine and serving requests
};

enum SystemFeatures		// Used by requiredfeatures
{
	Standard		= 0,	// By defult, everything requires a node
	GUISupport		= 1,	// GUI support is needed, thus QApplication should be launched instead of simple QCoreApplication
};

enum LogLevel
{
	Info		= 0,	// All kind of information for normal user
	Debug		= 1,	// Specific information for developement purposes, might not be understandable for user
	Warning		= 2,	// Situaion that differ from normal situation, but system within constraints, does
				// not require imminent interaction from user side
	Critical		= 3,	// serious condition, but system is stable, but requires imminent attention
	Fatal		= 4,	// Component in critical state, cannot operate and requires imminent user interaction
};

enum ImplementationLevel
{
	NotImplemented	= 0,	// Plugin is not implemented at all, not expected to do anything
	Developement	= 1,	// Plugin has implementation, but not considered to be stable (or in change)
	Stable		= 2	// Plugins has implementation and could be used in live environment 
};

/*
enum DataType			// used to define what type of values could be written to or read from an entity register
{
	nodatatype		= 0,
	boolean		= 1,
	bit			= 1,
//    byte		= 2,
	integer		= 3,
	floating		= 4,
	string		= 5,
	listelement		= 6
} dt;
*/
enum ConnectionStage
{
	NetOffline		= 0,	// No network is currently used
	NetBeacon		= 1,	// Searching for peers via Beacon subsystem
	NetConnecting	= 2,	// In connection state
	NetOnline		= 4,	// Connection is online and maintained
	NetError		= 8	// Connection has error
};

enum SettingShortcuts
{
	Conf_NodeRole	= 0,
	Conf_MatixId	= 1,
	Conf_Port		= 2,
	Conf_IP			= 3,

	Conf_DB_Type    = 4,
	Conf_DB_Host	= 5,
	Conf_DB_Name	= 6,
	Conf_DB_User	= 7,
	Conf_DB_Pass    = 8,
	Conf_DB_Port    = 9,

	Conf_SslServerCert = 10,
	Conf_SslServerKey   = 11,

	Conf_GUI		= 12
};

enum NodeStages
{
	BootUp		= 1,	// Before beacon stage
	Aligning		= 2,	// Beaconing, role is not yet decided
	Running		= 3	// Role and others are set and running in full power
};


enum HUDZoneTypes	// used for bitchecking zones
{
	HZ_CodeBase    = 0,
	HZ_CodeControl = 1,
	HZ_CodeValue   = 2,
	HZ_CodeLogic   = 4
};


enum HUDTypes
{
	HT_CodeBase		= 65536,
	HT_CodeControl	= HT_CodeBase + HZ_CodeControl,
	HT_CodeValue	= HT_CodeBase + HZ_CodeValue,
	HT_CodeLogic	= HT_CodeBase + HZ_CodeLogic
};

enum HUDVisualAid
{
	HV_Selected    = 1,
	HV_UpperSlot   = 2,
	HV_LowerSlot   = 4,
};


constexpr auto NR_UNDECIDED = "undecided";
constexpr auto NR_MASTER = "master";
constexpr auto NR_SLAVE = "slave";


/* Here comes the de facto industrial standard list of user attributes and so. We could reinvent the wheel here, but we certainly
do not want a situation, when a developer has to have a table containing the different naming for the same object in different systems.
But, to make the plugins compatible on the long run, all defines WILL HAVE a fixed integer value, that would not change during the course
of the project.

Most of these defines has default values, but those are defined, uploaded and handled by the NodeCore itself. 

These defines are automatically imported into the plugins via this file, no import needed :)
*/


enum Attributes
{
	STATE_ON 			= 1,
	STATE_OFF 			= 2,
	STATE_HOME 			= 3,
	STATE_NOT_HOME 		= 4,
	STATE_UNKNOWN 		= 5,
	STATE_OPEN 			= 6,
	STATE_OPENING 		= 7,
	STATE_CLOSED 		= 8,
	STATE_CLOSING 		= 9,
	STATE_PLAYING 		= 10,
	STATE_PAUSED 		= 11,
	STATE_IDLE 			= 12,
	STATE_STANDBY 		= 13,
	STATE_ALARM_DISARMED 	= 14,
	STATE_ALARM_ARMED_HOME 	= 15,
	STATE_ALARM_ARMED_AWAY 	= 16,
	STATE_ALARM_ARMED_NIGHT 	= 17,
	STATE_ALARM_ARMED_CUSTOM_BYPASS = 18,
	STATE_ALARM_PENDING 	= 19,
	STATE_ALARM_ARMING 		= 20,
	STATE_ALARM_DISARMING 	= 21,
	STATE_ALARM_TRIGGERED 	= 22,
	STATE_LOCKED 		= 23,
	STATE_UNLOCKED 		= 24,
	STATE_UNAVAILABLE 		= 25,
	STATE_OK 			= 26,
	STATE_PROBLEM 		= 27,

// GENERAL ATTRIBUTES
	ATTR_TEMPERATURE_9		= 100,
	ATTR_TEMPERATURE_10		= 101,
	ATTR_TEMPERATURE_11		= 102,
	ATTR_TEMPERATURE_12		= 103,
	ATTR_TEMPERATURE		= ATTR_TEMPERATURE_9,

// I2C RELATED
	I2C_PRESENT			= 200,
	I2C_QUICK			= 201,
	I2C_RECEIVE_BYTE		= 202,
	I2C_WRITE_BYTE		= 203,
	I2C_READ_BYTE		= 204,
	I2C_WRITE_WORD		= 205,
	I2C_READ_WORD		= 206,
	I2C_PROCESS_CALL		= 207,
	I2C_BLOCK_WRITE		= 208,
	I2C_BLOCK_READ		= 209,
	I2C_BLOCK_PROCESS_CALL	= 210,

// UPS RELATED (based on APC, but should be used as GENERAL

	UPS_MESSAGESTART		= 1001,
	UPS_DATE			= 1002,
	UPS_HOSTNAME		= 1003,
	UPS_VERSION			= 1004,
	UPS_UPSNAME			= 1005,
	UPS_DRIVER			= 1006,
	UPS_UPSMODE			= 1007,
	UPS_MODEL			= 1008,
	UPS_STATUS			= 1009,
	UPS_LINEV			= 1010,
	UPS_LOADPCT			= 1011,
	UPS_BCHARGE			= 1012,
	UPS_TIMELEFT		= 1013,
	UPS_MBATTCHG		= 1014,
	UPS_MINTIMEL		= 1015,
	UPS_MAXTIME			= 1016,
	UPS_OUTPUTV			= 1017,
	UPS_SENSE			= 1018,
	UPS_DWAKE			= 1019,
	UPS_DSHUTD			= 1020,
	UPS_LOTRANS			= 1021,
	UPS_HITRANS			= 1022,
	UPS_RETPCT			= 1023,
	UPS_ITEMP			= 1024,
	UPS_ALARMDEL		= 1025,
	UPS_BATTV			= 1026,
	UPS_LINEFREQ		= 1027,
	UPS_LASTXFER		= 1028,
	UPS_NUMXFERS		= 1029,
	UPS_TONBATT			= 1030,
	UPS_CUMONBATT		= 1031,
	UPS_XOFFBATT		= 1032,
	UPS_SELFTEST		= 1033,
	UPS_STESTI			= 1034,
	UPS_STATFLAG		= 1035,
	UPS_MANDATE			= 1036,
	UPS_SERIALNO		= 1037,
	UPS_BATTDATE		= 1038,
	UPS_NOMOUTV			= 1039,
	UPS_NOMBATTV		= 1040,
	UPS_FIRMWARE		= 1041,
	UPS_MESSAGEENT		= 1042
};

// This is the structure of the event passed among plugins and nodes and serialized for network transport
// We are not encapsulating this for now.

class HyEventDesc
{
public:
	HyEventDesc() {}
	~HyEventDesc() {}

	QString name;
//	DataType type;
	int mode;		// read, write, etc
	double min;		// possible minimum value
	double max;		// possible maximum value
	QStringList opts;	// if event value is from a list, this list should contain accepted values
};

class HyEvent
{
public:
	HyEvent()  {}
	~HyEvent() {}

	int id;			// id of the event
	QVariant value;
};

// We do use "packs" to transfer multiple event at the same time. This is needed for example when a node is connecting
// to the already existing mesh and queries the current state.

class HyEventPack
{
public:
	HyEventPack()  {}
	~HyEventPack() {}

	QList<HyEvent *> events;
};

class NodeCoreInfo
{
public:
	NodeCoreInfo()  {}
	~NodeCoreInfo() {}
	QString noderole;
	QString matrixid;
	QString nodeid;
	QString ip;			// should support multiple interface!
	QString port;
	QString build_date;
	QString version;
	QString sessionid;
};

/* DataPack base. All specialised events and objects should be inherited from this
*/
class DataPack
{
friend class CoreServer;
friend class UniCore;
friend class Slotter;

public:
	 DataPack() 
	 {
	    _isText = true;
	    _compressed = false;
	 }
	 DataPack(QString text)
	 {
	    _compressed = false;
	     setText(text);
	 }

	 DataPack(QByteArray ar)
	 {
	    _compressed = false;
	    setBinary(ar);
	 }

	 DataPack(const DataPack* old)
	 {
	     _socketid = old->_socketid;
	     _isText = old->_isText;
	     _text_payload = old->_text_payload;
	     _binary_payload = old->_binary_payload;
	 }
	
	QString textPayload()      { return _text_payload;  }
	QByteArray binaryPayload() { return _binary_payload; }

	bool isText() 	   { return _isText;     }
	bool compressed()  { return _compressed; }
	QString entityId() { return _entityid;   }
	int socketId()     { return _socketid;   }

	 virtual ~DataPack() {}
	QHash<QString, QVariant> attributes;

	void setSource(QString source) { _source = source; }
	void setDestination(QString destination) { _destination = destination; }
	QString source() { return _source; }
	QString destination() { return _destination; }

protected:
	 void setText(QString txt)
	 {
	     _isText = true;
	     _text_payload = txt;
	 }

	 void setBinary(QByteArray arr)
	 {
	     _isText = false;
	     _binary_payload = arr;
	 }

	void setEntityId(QString _eid)
	{
	    _entityid=_eid;
	}

	void setSocketId(int id)
	{
	    _socketid = id;
	}

protected:
	int _socketid;
	QString _entityid;
	bool _compressed;
	bool _isText;
	QString _text_payload;
	QByteArray _binary_payload;
	QString _source;
	QString _destination;
};

#endif