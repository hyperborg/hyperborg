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

#define NODE_RESTART_CODE 2222

const QString HYPERBORG_VERSION         = QStringLiteral("1.0.0");
const QString HYPERBORG_BUILD_TIMESTAMP = QStringLiteral(__DATE__ " " __TIME__);

class UniCore;
class CoreServer;
class Slotter;

enum Unit
{
    NotDefined		= 0,
    Any				= 1,
    Celsius			= 2,
    Farenheit		= 3,
	W				= 4,
    Wm2				= 5,
	kW				= 6,	
	kWh				= 7,
	kVA				= 8,
	kVar			= 9,
	Volt			= 10,
	Amper			= 11,
	Hz				= 12,
	Ohm				= 13,
	KOhm			= 14,
	MOhm			= 15,
	Percent			= 16,
	PercentPerSec	= 17,
	Second			= 18,
	Minute			= 19,
	Hour			= 20,
	Day				= 21 

};

enum Platforms
{
	AIR_QUALITY				= 1,
	ALARM_CONTROL_PANEL		= 2,
	BINARY_SENSOR			= 3, 
	BUTTON					= 4, 
	CALENDAR				= 5,
	CAMERA					= 6,
	CLIMATE					= 7,
	COVER					= 8,
	DATASET					= 9,
	DEVICE_TRACKER			= 10,
	FAN						= 11,
	GEO_LOCATION			= 12,
	HUMIDIFIER				= 13,
	IMAGE_PROCESSING		= 14,
	LIGHT					= 15,
	LOCK					= 16,
	MAILBOX					= 17,
	MEDIA_PLAYER			= 18,
	NOTIFY					= 19,
	NUMBER					= 20,
	REMOTE					= 21,
	SCENE					= 22,
	SELECT					= 23,
	SENSOR					= 24,
	SIREN					= 25,
	STT						= 26,
	SWITCH					= 27,
	TTS						= 28,
	VACUUM					= 29,
	UPDATE					= 30,
	WATER_HEATER			= 31,
	WEATHER					= 32
};

//EntityProperties is used at indexing data in HFS

enum EnityProperties
{
	// General properties
	ASSUMED_STATE	= 1,		
};


enum PackCommands
{
	CommandNotDefined	= -1,
	NOP		   			= 0,
	Ping				= 1,
	RegisterEntity		= 2,
	UnregisterEntity    = 3,
	RequestEntity		= 4,
	SystemEvent			= 5,
	DataChangeRequest   = 6,
	SetValue			= 7
};

enum InterestModes
{
	SingleInterest		= 0,
	SystemInterest		= 1
};

enum ChangeRequestReply
{
    Ok	       		= 1 ,	// Change requested is usuable as is
    OkWithModifications	= 2 ,	// Change is ok with the enclosed modifications
    SetValues		= 4,	// For convineince reason (from mesh to a given entity) -> same as OkWitModifications
    NotAcceptable	= 8 	// Change request should be dropped ($$ISSUE might be included for reason)
};

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

enum OpenMode
{
	ReadOnly  = 0,
	ReadWrite = 1,
	WriteOnly = 2
};


enum DataType			// used to define what type of values could be written to or read from an entity register
{
	DT_NoDataType	= 0,
	DT_Boolean		= 1,
	DT_Bit			= 2,
	DT_Byte			= 3,
	DT_Short		= 4,
	DT_UShort		= 5,
	DT_Integer		= 6,
	DT_UInteger		= 7,
	DT_Floating		= 8,
	DT_String		= 9,
	DT_ListElement	= 10,
	DT_U16			= DT_Short,
	DT_I16			= DT_Short,
	DT_U32			= DT_UInteger,
	DT_I32			= DT_Integer,
	DT_BitField16	= 11,
	DT_BitField32	= 12,
	DT_File			= 13,
	DT_StringList	= 14
};


enum ConnectionStage
{
	NetOffline		= 0,	// No network is currently used
	NetBeacon		= 1,	// Searching for peers via Beacon subsystem
	NetConnecting	= 2,	// In connection state
	NetOnline		= 4,	// Connection is online and maintained
	NetError		= 8	// Connection has error
};

// Setting macros
#define	Conf_NodeRole	"config.role"
#define	Conf_MatixId	"config.matrixid"
#define	Conf_Port	    "config.port"
#define	Conf_IP		    "config.ip"

#define	Conf_DB_Type    "config.db_type"
#define	Conf_DB_Host	"config.db_host"
#define	Conf_DB_Name	"config.db_name"
#define	Conf_DB_User	"config.db_user"
#define	Conf_DB_Pass    "config.db_pass"
#define	Conf_DB_Port    "config.db_port"

#define	Conf_SslServerCert "config.ssl_cert"
#define	Conf_SslServerKey   "config.ssl_key"

#define	Conf_GUI		"config.gui"

enum NodeStages
{
	BootUp		= 1,	// Before beacon stage
	Aligning		= 2,	// Beaconing, role is not yet decided
	Running		= 3	// Role and others are set and running in full power
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

enum HFS_HeaderIdx
{
	HFSIDX_Value					= 0,
	HFSIDX_AttrId					= 1,
	HFSIDX_Conext					= 2,
	HFSIDX_IOMode					= 3,
	HFSIDX_DataType					= 4,
	HFSIDX_Unit						= 5,
	HFSIDX_Path						= 6,
	HFSIDX_LastModification			= 7,
	HFSIDX_Name						= 8,
	HFSIDX_Comment					= 9,
	HFSIDX_HistoryDepth				= 10,
	HFSIDX_END						= 11
};

enum Context
{
	Attribute					    = 1,			// It just contains some value
	Configuration					= 2,			// Contains JSON file
	DataSet							= 3,			// Contains updateable database in JSON format
	Log								= 4,
	File							= 5				// Attribute contains file content
};

enum States
{
	STATE_ON						= 1,
	STATE_OFF						= 2,
	STATE_HOME						= 3,
	STATE_NOT_HOME					= 4,
	STATE_UNKNOWN					= 5,
	STATE_OPEN						= 6,
	STATE_OPENING					= 7,
	STATE_CLOSED					= 8,
	STATE_CLOSING					= 9,
	STATE_PLAYING					= 10,
	STATE_PAUSED					= 11,
	STATE_IDLE						= 12,
	STATE_STANDBY					= 13,
	STATE_ALARM_DISARMED			= 14,
	STATE_ALARM_ARMED_HOME			= 15,
	STATE_ALARM_ARMED_AWAY			= 16,
	STATE_ALARM_ARMED_NIGHT			= 17,
	STATE_ALARM_ARMED_CUSTOM_BYPASS = 18,
	STATE_ALARM_PENDING				= 19,
	STATE_ALARM_ARMING				= 20,
	STATE_ALARM_DISARMING			= 21,
	STATE_ALARM_TRIGGERED			= 22,
	STATE_LOCKED					= 23,
	STATE_UNLOCKED					= 24,
	STATE_UNAVAILABLE				= 25,
	STATE_OK						= 26,
	STATE_PROBLEM					= 27
};

enum Attributes
{

// GENERAL ATTRIBUTES
	TEMPERATURE_9		= 100,
	TEMPERATURE_10		= 101,
	TEMPERATURE_11		= 102,
	TEMPERATURE_12		= 103,
	TEMPERATURE			= TEMPERATURE_9,

// I2C RELATED
	I2C_PRESENT			= 200,
	I2C_QUICK			= 201,
	I2C_RECEIVE_BYTE	= 202,
	I2C_WRITE_BYTE		= 203,
	I2C_READ_BYTE		= 204,
	I2C_WRITE_WORD		= 205,
	I2C_READ_WORD		= 206,
	I2C_PROCESS_CALL	= 207,
	I2C_BLOCK_WRITE		= 208,
	I2C_BLOCK_READ		= 209,
	I2C_BLOCK_PROCESS_CALL	= 210,

// UPS RELATED (based on APC, but should be used as GENERAL

	UPS_MESSAGESTART	= 1001,
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
	UPS_MESSAGEENT		= 1042,
													// Inverter related attributes
	INV_MODEL = 2001,
	INV_SN = 2002,
	INV_PN = 2003,
	INV_MODEL_ID = 2004,
	INV_NUM_PV_STRINGS = 2005,
	INV_NUM_MPP_TRACKERS = 2006,
	INV_RATED_POWER = 2007,
	INV_MAX_ACTIVE_POWER = 2008,
	INV_MAX_APPARENT_POWER = 2009,
	INV_MAX_REACTIVE_POWER_TO_GRID = 2010,
	INV_MAX_REACTIVE_POWER_FROM_GRID = 2011,
	INV_STATE_1 = 2012,
	INV_STATE_2 = 2013,
	INV_STATE_3 = 2014,
	INV_ALARM_1 = 2015,
	INV_ALARM_2 = 2016,
	INV_ALARM_3 = 2017,
	INV_PV1_VOLTAGE = 2018,
	INV_PV1_CURRENT = 2019,
	INV_PV2_VOLTAGE = 2020,
	INV_PV2_CURRENT = 2021,
	INV_PV3_VOLTAGE = 2022,
	INV_PV3_CURRENT = 2023,
	INV_PV4_VOLTAGE = 2024,
	INV_PV4_CURRENT = 2025,
	INV_INPUT_POWER = 2026,
	INV_LINE_VOLTAGE_A_B = 2027,
	INV_LINE_VOLTAGE_B_C = 2028,
	INV_LINE_VOLTAGE_C_A = 2029,
	INV_PHASE_A_VOLTAGE = 2030,
	INV_PHASE_B_VOLTAGE = 2031,
	INV_PHASE_C_VOLTAGE = 2032,
	INV_PHASE_A_CURRENT = 2033,
	INV_PHASE_B_CURRENT = 2034,
	INV_PHASE_C_CURRENT = 2035,
	INV_PEAK_ACTIVE_POWER_OF_DAY = 2036,
	INV_ACTIVE_POWER = 2037,
	INV_REACTIVE_POWER = 2038,
	INV_POWER_FACTOR = 2039,
	INV_GRID_FREQUENCY = 2040,
	INV_EFFICIENCY = 2041,
	INV_INTERNAL_TEMPERATURE = 2042,
	INV_INSULATION_RESISTANCE = 2043,
	INV_DEVICE_STATUS = 2044,
	INV_FAULT_CODE = 2045,
	INV_STARTUP_TIME = 2046,
	INV_SHUTDOWN_TIME = 2047,
	INV_ACCUMULATED_ENERGY_YIELD = 2048,
	INV_DAILY_ENERGY_YIELD = 2049,
	INV_ACTIVE_ADJUSTMENT_MODE = 2050,
	INV_ACTIVE_ADJUSTMENT_VALUE = 2051,
	INV_ACTIVE_ADJUSTMENT_COMMAND = 2052,
	INV_REACTIVE_ADJUSTMENT_MODE = 2053,
	INV_REACTIVE_ADJUSTMENT_VALUE = 2054,
	INV_REACTIVE_ADJUSTMENT_COMMAND = 2055,
	INV_BATTERY_RUNNING_STATUS = 2056,
	INV_BATTERY_CHARGE_AND_DISCHARGE_POWER = 2057,
	INV_BATTERY_SOC = 2058,
	INV_BATTERY_CHARGE_CAPACITY_OF_DAY = 2059,
	INV_BATTERY_DISCHARGE_CAPACITY_OF_DAY = 2060,
	INV_POWERMETER_ACTIVE_POWER = 2061,
	INV_OPTIMIZER_TOTAL_NUMBER = 2062,
	INV_OPTIMIZER_ONLINE = 2063,
	INV_OPTIMIZER_FEATURE_DATA = 2064,
	INV_SYSTEM_TIME = 2065,
	INV_Q_U_CHARACTERISTIC_CURVE_MODE = 2066,
	INV_Q_U_DISPATCH_TRIGGER_POWER = 2067,
	INV_FIXED_ACTIVE_POWER_DERATED = 2068,
	INV_REACTIVE_POWER_COMPENSATION_PF = 2069,
	INV_REACTIVE_POWER_COMPENSATION_QS = 2070,
	INV_ACTIVE_POWER_PERCENTAGE_DERATING = 2071,
	INV_FIXED_reACTIVE_POWER_DERATED = 2072,
	INV_REACTIVE_POWER_COMPENSATION_AT_NIGHT = 2073,
	INV_COSFI_CCHARACTERISTIC_CURVE = 2074,
	INV_Q_U_CHARACHTERISTIC_CURVE = 2075,
	INV_PF_U_CHARACTERISTIC_CURVE = 2076,
	INV_REACTIVE_POWER_ADJUSTMENT_TIME = 2077,
	INV_Q_U_POWER_PERCENTAGE_TO_EXIT_SCHEDULING = 2078,
	INV_STARTUP = 2079,
	INV_SHUTDOWN = 2080,
	INV_GRID_CODE = 2081,
	INV_REACTIVE_POWER_CHANGE_GRADIENT = 2082,
	INV_ACTIVE_POWER_CHANGE_GRADIENT = 2083,
	INV_SCHEDULE_INSTRUCTION_VALID_DURATION = 2084,
	INV_TIME_ZONE = 2085,
	INV_BATTERY_WORKING_MODE = 2086,
	INV_BATTERY_TIME_OF_USE_ELECTRICITY_PRICE = 2087,
	INV_BATTERY_PRICE_PERIODS = 2088,
	INV_BATTERY_LCOE = 2089,
	INV_BATTERY_MAXIMUM_CHARGING_POWER = 2090,
	INV_BATTERY_MAXIMUM_DISCHARGING_POWER = 2091,
	INV_BATTERY_POWER_LIMIT_GRID_TIED_POINT = 2092,
	INV_BATTERY_CHARGE_CUTOFF_CAPACITY = 2093,
	INV_BATTERY_DISCHARGE_CUTOFF_CAPACITY = 2094,
	INV_BATTERY_FORCED_CHARGING_DISCHARGING_PERIOD = 2095,
	INV_BATTERY_FORCED_CHARGING_DISCHARGING_POWER = 2096,
	INV_BATTERY_FIXED_CHARGING_DISCHARGING_PERIODS = 2097,

// device status
	INV_INITIALIZING								= 2098,
	INV_DETECTING_ISO								= 2099,
	INV_DETECTING_IRRIDATION						= 2100,
	INV_DETECTING_GRID								= 2101,
	INV_STARTING									= 2102,
	INV_ON_GRID										= 2103,
	INV_ON_GRID_POWER_LIMIT							= 2104,
	INV_ON_GRID_SELF_DERATING						= 2105,
	INV_SHUTDOWN_FAULT								= 2106,
	INV_SHUTDOWN_COMMAND							= 2107,
	INV_SHUTDOWN_OVGR								= 2108,
	INV_SHUTDOWN_COMMUNICATION_DISCONNECTED			= 2109,
	INV_POWER_LIMIT									= 2110,
	INV_SHUTDOWN_START_MANUALLY						= 2111,
	INV_SHUTDOWN_DC_SWITCH_OFF						= 2112,
	INV_GRID_DISPATCH_Q_U_CURVE						= 2113,
	INV_NO_IRRIDATION								= 2114,
	INV_SPOT_CHECK									= 2115,
	INV_SPOT_CHECKING								= 2116,
	INV_INSPECTING									= 2117,
	INV_AFCI_SELF_CHECK								= 2118,
	INV_IV_SCANNING									= 2119,
	INV_DC_INPUT_DETECTION							= 2120

};

class HyValue
{
public:
    HyValue(QVariant v=QVariant(), Unit u=Unit::NotDefined) 
    {
		value = v;
		unit  = u;
    }
    ~HyValue() {}

    QVariant value;
    Unit unit;
};

/* DataPack base. All specialised events and objects should be inherited from this
*/
class DataPack
{
friend class CoreServer;
friend class UniCore;
friend class Slotter;
friend class HyObject;

public:
	 DataPack() 
	 {
		_command = PackCommands::CommandNotDefined;
	    _isText = true;
	    _compressed = false;
	 }
	 DataPack(QString text)
	 {
		_command = PackCommands::CommandNotDefined;
	    _compressed = false;
	     setText(text);
	 }

	 DataPack(QByteArray ar)
	 {
		_command = PackCommands::CommandNotDefined;
	    _compressed = false;
	    setBinary(ar);
	 }

	 DataPack(const DataPack* old)
	 {
		_command = old->_command;
	    _socketid = old->_socketid;
	    _isText = old->_isText;
	    _text_payload = old->_text_payload;
	    _binary_payload = old->_binary_payload;
	    _entityid = old->_entityid;
	    attributes = old->attributes;
	 }

	 static int serialize(DataPack* pack)	// we fill the the block with the sended data (binary or text)
	 {										// we could apply format versioning here, or compressing data
		 if (!pack) return 0;

		 QStringList retlst;

		 // We overwrite the attributes before serialization. This way if an entity would 
		 // create the same value (badly behaving), it is overwritten here
		 pack->attributes.insert("$$P_ENTITY", pack->_entityid);
		 pack->attributes.insert("$$P_SOURCE", pack->_source);
		 pack->attributes.insert("$$P_DESTINATION", pack->_destination);
		 pack->attributes.insert("$$P_COMMAND", pack->_command);

		 QHashIterator<QString, QVariant> it(pack->attributes);
		 while (it.hasNext())
		 {
			 it.next();
			 retlst << QString(it.key() + "=" + it.value().toString());
		 }
		 pack->setText(retlst.join("\n"));
		 return 1;
	 }

	 static int deserialize(DataPack* pack)		// we extract attributes from the text/binary data received 
	 {											// through socket. We could apply format versioning here or
												// decompressing data
		 int retint = 1;
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
			 pack->_entityid = pack->attributes.value("$$P_ENTITY", "").toString();
			 pack->_source = pack->attributes.value("$$P_SOURCE", "").toString();
			 pack->_destination = pack->attributes.value("$$P_DESTINATION", "").toString();
			 pack->_command = pack->attributes.value("$$P_COMMAND", CommandNotDefined).toInt();
		 }
		 else // binary - we do not process it yet
		 {
		 }
		 return retint;
	 }

	
	QString textPayload()      { return _text_payload;  }
	QByteArray binaryPayload() { return _binary_payload; }

	bool isText() 	   { return _isText;     }
	bool compressed()  { return _compressed; }
	QString entityId() { return _entityid;   }
	int socketId()     { return _socketid;   }
	int command()	   { return _command;	 }

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

	void setCommand(int c)
	{
		_command = c;
	}


protected:
	int _socketid;
	int _command;
	QString _entityid;
	bool _compressed;
	bool _isText;
	QString _text_payload;
	QByteArray _binary_payload;
	QString _source;
	QString _destination;
};

#endif