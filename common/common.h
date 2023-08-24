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
#include <QDateTime>
#include <QPair>

#define NODE_RESTART_CODE 2222

const QString HYPERBORG_VERSION         = QStringLiteral("1.0.0");
const QString HYPERBORG_BUILD_TIMESTAMP = QStringLiteral(__DATE__ " " __TIME__);

class UniCore;
class CoreServer;
class Slotter;

typedef QPair<QString, QVariant> StackPair;

enum HFS_Flag
{
    HFS_None        = 0,      // No flag is defined
    HFS_PlaceHolder = 1,      // This item is created by HFS as a required item, but noone is providing it currently
    HFS_Provided    = 2,      // This item is provided by either system or outside plugin
    HFS_System      = 4,      // This item is maintained by the system
    HFS_General     = 8,      // This item is non-item specific (like creation timestamps)
    HFS_Required    = 16,     // This item should be provided by plugin in order to the parent item function correctly (cast error if not provided)
    HFS_Optional    = 32,     // This item is optional (only warning is being casted when not provided upon use)
    HFS_Item        = 64,     // Item is a general item (see platform() call for the actualy type and role
    HFS_Attribute   = 128,    // Item is an attribute role of its parent
    HFS_Method      = 256     // Item is a method of its parents
};

enum HFS_Subscription_Flag
{
    HFSSF_NoFlag            = 0,
    HFSSF_AnyValueTrigger   = 1,    // Notification is triggered if provider updates (even if the same value is fed)
    HFSSF_
};

enum Unit
{
    NotDefined      = 0,
    ValueInItself   = 1,
    Level           = ValueInItself,
    Celsius         = 2,
    Farenheit       = 3,
    W               = 4,
    Wm2             = 5,
    kW              = 6,
    kWh             = 7,
    kVA             = 8,
    kVar            = 9,
    Volt            = 10,
    Amper           = 11,
    Hz              = 12,
    Ohm             = 13,
    KOhm            = 14,
    MOhm            = 15,
    Percent         = 16,
    PercentPerSec   = 17,
    Second          = 18,
    Minute          = 19,
    Hour            = 20,
    Day             = 21,
    Kmh             = 22,
    Mph             = 23,
    Compass         = 24,        // range 0 (north) -> 90 (east) -> 180 south -> 270 west
    HgMM            = 25,
    hPa             = 26,
    InHg            = 27,       // Inch in Mercury
    Meter           = 28,
    Kilometer       = 29,
    Centimeter      = 30,
    Milimeter       = 31,
    Inch            = 32,
    Mile            = 33,
    MiliBar         = 34,
    String          = 35
};

enum Platforms
{
    GENERAL                 = 1,
    PROPERTY                = 2,
    STATUS                  = 3,
    METHOD                  = 4,
    NOT_USED_1              = 5,
    NOT_USED_2              = 6,
    NOT_USED_3              = 7,
    NOT_USED_4              = 8,
    NOT_USED_5              = 9,
    NOT_USED_6              = 10,
    AIR_QUALITY             = 11,
    ALARM_CONTROL_PANEL     = 12,
    BINARY_SENSOR           = 13, 
    BUTTON                  = 14, 
    RELAY                   = 15,
    CALENDAR                = 16,
    CAMERA                  = 17,
    CLIMATE                 = 18,
    COVER                   = 19,
    DATASET                 = 20,
    DEVICE_SCANNER          = 21,
    DEVICE_TRACKER          = 22,
    FAN                     = 23,
    GEO_LOCATION            = 24,
    HUMIDIFIER              = 25,
    IMAGE_PROCESSING        = 26,
    LIGHT                   = 27,
    LOCK                    = 28,
    MAILBOX                 = 29,
    MEDIA_PLAYER            = 30,
    NOTIFY                  = 31,
    NUMBER                  = 32,
    REMOTE                  = 33,
    SCENE                   = 34,
    SELECT                  = 35,
    SENSOR                  = 36,
    SIREN                   = 37,
    STT                     = 38,
    SWITCH                  = 39,
    TTS                     = 40,
    VACUUM                  = 41,
    UPDATE                  = 42,
    WATER_HEATER            = 43,
    WEATHER                 = 44,
    PLATFORM_LAST           = 45
};

// Attribute defines

enum PackCommands
{
    CommandNotDefined   = -1,
    NOP                 = 0,
    Ping                = 1,
    RegisterEntity      = 2,
    UnregisterEntity    = 3,
    RequestEntity       = 4,
    SystemEvent         = 5,

    // HFS
    HFSStart            = 6,    // Range marker. Should be the same value as the _first_HFS command
    HFSDataChangeRequest= 6,
    HFSSetValue         = 7,
    HFSCreatePath       = 8,
    HFSLog              = 9,
    HFSEnd              = 9     // Range marker. Should be the same value as the _last_ HFS command

};

enum InterestModes
{
    SingleInterest      = 0,
    SystemInterest      = 1
};

enum ChangeRequestReply
{
    Ok                  = 1 ,   // Change requested is usuable as is
    OkWithModifications = 2 ,   // Change is ok with the enclosed modifications
    SetValues           = 4,    // For convineince reason (from mesh to a given entity) -> same as OkWitModifications
    NotAcceptable       = 8     // Change request should be dropped ($$ISSUE might be included for reason)
};

enum PowerOptions
{
    NonCritical         = 0,    // this is the default, we do not care if node/plugin is unplugged
                                // in power failure, we are not expecting to see these nodes, thus
                                // there is no waiting for communication timeout
    NeedsShutdown       = 1,    // it requires some time to properly shut down its plugins and itself
                                // ex. if node contains dimmable lamps, in order to save energy and lower
                                // load on aux/emergency power, it should turn all laps to 0 before
                                // quitting
    KeepAlive           = 2,    // This should be kept live at all cost
    HasUPS              = 4,    // This node/plugin has UPS power wired in (they connected to emergency power)
    PowerSave           = 8     // This node/plugin could be instructed to be in powersave mode
                                // For example if there are designated plugs containing rechargeable elements
                                // phone chargers, induction chargers 
};

enum SystemStates
{
    Normal              = 0,    // System is normal state (no config modification, no new nodes, no discovery,
                                // failures handled mostly as warnings
    Installation        = 1,    // Config modification enabled, new units could be added, alarm surpressed 
    Alarm               = 2     // Alarm system reported alarm situation or not reacheable (all failure is
                                // considered to be fatal (unit loss triggers alarm)
};

enum PluginStates
{
    Offline             = 0,    // The plugin is in a non-operable state. There is some problem or init() failed
    Disabled            = 1,    // The plugin is capable of doing something, but it does not, since it was disabled
    Online              = 2     // Plugin is fine and serving requests
};

enum SystemFeatures     // Used by requiredfeatures
{
    Standard            = 0,    // By defult, everything requires a node
    GUISupport          = 1,    // GUI support is needed, thus QApplication should be launched instead of simple QCoreApplication
};

enum LogLevel
{
    Info                = 0,    // All kind of information for normal user
    Debug               = 1,    // Specific information for developement purposes, might not be understandable for user
    Warning             = 2,    // Situaion that differ from normal situation, but system within constraints, does
                                // not require imminent interaction from user side
    Critical            = 3,    // serious condition, but system is stable, but requires imminent attention
    Fatal               = 4,    // Component in critical state, cannot operate and requires imminent user interaction
};

enum ImplementationLevel
{
    NotImplemented      = 0,    // Plugin is not implemented at all, not expected to do anything
    Developement        = 1,    // Plugin has implementation, but not considered to be stable (or in change)
    Stable              = 2     // Plugins has implementation and could be used in live environment 
};

enum OpenMode
{
    ReadOnly            = 0,
    ReadWrite           = 1,
    WriteOnly           = 2
};

enum DataType           // used to define what type of values could be written to or read from an entity register
{
    DT_NoDataType       = 0,
    DT_Boolean          = 1,
    DT_Bit              = 2,
    DT_Byte             = 3,
    DT_Short            = 4,
    DT_UShort           = 5,
    DT_Integer          = 6,
    DT_UInteger         = 7,
    DT_Float            = 8,
    DT_Double           = 9,
    DT_String           = 10,
    DT_ListElement      = 11,
    DT_U16              = DT_Short,
    DT_I16              = DT_Short,
    DT_U32              = DT_UInteger,
    DT_I32              = DT_Integer,
    DT_BitField16       = 12,
    DT_BitField32       = 13,
    DT_File             = 14,
    DT_StringList       = 15,
    DT_Numeric          = 16,
    DT_TimeStamp        = 17
};

enum DBColumnType
{
    DBF_SameAsDataType  = 0,
    DBF_Float           = 1,
    DBF_Double          = 2,
    DBF_Numeric         = 3,
    DBF_Integer         = 4,
    DBF_VarChar         = 5,
    DBF_TimeStamp       = 6
};

enum ConnectionStage
{
    NetOffline          = 0,    // No network is currently used
    NetBeacon           = 1,    // Searching for peers via Beacon subsystem
    NetConnecting       = 2,    // In connection state
    NetOnline           = 4,    // Connection is online and maintained
    NetError            = 8     // Connection has error
};

// Setting macros
#define Bootup_Name             "bootup.name"
#define Bootup_NodeRole         "bootup.role"
#define Bootup_MatixId          "bootup.matrixid"
#define Bootup_Port             "bootup.port"
#define Bootup_IP               "bootup.ip"

#define Bootup_SslServerCert    "bootup.ssl_cert"
#define Bootup_SslServerKey     "bootup.ssl_key"

#define Bootup_GUI              "bootup.gui"
#define Bootup_ConfigFile       "bootup.config_file"

#define Config_DB_Type          "config.db_type"
#define Config_DB_Host          "config.db_host"
#define Config_DB_Name          "config.db_name"
#define Config_DB_User          "config.db_user"
#define Config_DB_Pass          "config.db_pass"
#define Config_DB_Port          "config.db_port"

#define Config_MainQML          "config.mainqml"
#define Config_HUDMode          "config.hudmode"
#define Config_FullScreen       "config.fullscreen"

#define HFS_State               "hfs.state"
#define System_LogLine          "system.logline"
#define System_Log              "system.log"
#define System_BuildDate        "system.build_date"

#define System_Date_Year        "system.date.year"
#define System_Date_Month       "system.date.month"
#define System_Date_Day         "system.date.day"

#define System_Time_Hour        "system.time.hour"
#define System_Time_Minute      "system.time.minute"
#define System_Time_Second      "system.time.second"

#define System_Time_DayEpoch    "system.time.dayepoch"
#define System_Time_Epoch       "system.time.epoch"

enum NodeStages
{
    BootUp          = 1,    // Before beacon stage
    Aligning        = 2,    // Beaconing, role is not yet decided
    Running         = 3     // Role and others are set and running in full power
};

enum HFSStates
{
    HFSCreated              = 0,
    HFSBootInfoLoaded       = 1,
    HFSConfigLoaded         = 2
};

constexpr auto NR_UNDECIDED = "undecided";
constexpr auto NR_MASTER = "master";
constexpr auto NR_SLAVE = "slave";

enum HSMType
{
    HSM_HSMBase                     = 0,
    HSM_HSM                         = 1,
    HSM_Logic                       = 2,
    HSM_Flow                        = 3,
    HSM_SubFlow                     = 4,
    HSM_Job                         = 5,
    HSM_Task                        = 6,
    HSM_Port                        = 7,
    HSM_Wire                        = 8,
    HSM_LAST                        = 9
};

static QStringList HSMTypeStrings = { "HSMBase", "HSM", "Logic", "Flow", "SubFlow", "Job", "Task", "Port", "Wire", "LAST" };

enum States
{
    STATE_ON                        = 1,
    STATE_OFF                       = 2,
    STATE_HOME                      = 3,
    STATE_NOT_HOME                  = 4,
    STATE_UNKNOWN                   = 5,
    STATE_OPEN                      = 6,
    STATE_OPENING                   = 7,
    STATE_CLOSED                    = 8,
    STATE_CLOSING                   = 9,
    STATE_PLAYING                   = 10,
    STATE_PAUSED                    = 11,
    STATE_IDLE                      = 12,
    STATE_STANDBY                   = 13,
    STATE_ALARM_DISARMED            = 14,
    STATE_ALARM_ARMED_HOME          = 15,
    STATE_ALARM_ARMED_AWAY          = 16,
    STATE_ALARM_ARMED_NIGHT         = 17,
    STATE_ALARM_ARMED_CUSTOM_BYPASS = 18,
    STATE_ALARM_PENDING             = 19,
    STATE_ALARM_ARMING              = 20,
    STATE_ALARM_DISARMING           = 21,
    STATE_ALARM_TRIGGERED           = 22,
    STATE_LOCKED                    = 23,
    STATE_UNLOCKED                  = 24,
    STATE_UNAVAILABLE               = 25,
    STATE_OK                        = 26,
    STATE_PROBLEM                   = 27
};

enum Attributes
{

// GENERAL ATTRIBUTES
    TEMPERATURE_9       = 100,
    TEMPERATURE_10      = 101,
    TEMPERATURE_11      = 102,
    TEMPERATURE_12      = 103,
    TEMPERATURE         = TEMPERATURE_9,

// I2C RELATED
    I2C_PRESENT         = 200,
    I2C_QUICK           = 201,
    I2C_RECEIVE_BYTE    = 202,
    I2C_WRITE_BYTE      = 203,
    I2C_READ_BYTE       = 204,
    I2C_WRITE_WORD      = 205,
    I2C_READ_WORD       = 206,
    I2C_PROCESS_CALL    = 207,
    I2C_BLOCK_WRITE     = 208,
    I2C_BLOCK_READ      = 209,
    I2C_BLOCK_PROCESS_CALL  = 210,

// UPS RELATED (based on APC, but should be used as GENERAL

    UPS_MESSAGESTART    = 1001,
    UPS_DATE            = 1002,
    UPS_HOSTNAME        = 1003,
    UPS_VERSION         = 1004,
    UPS_UPSNAME         = 1005,
    UPS_DRIVER          = 1006,
    UPS_UPSMODE         = 1007,
    UPS_MODEL           = 1008,
    UPS_STATUS          = 1009,
    UPS_LINEV           = 1010,
    UPS_LOADPCT         = 1011,
    UPS_BCHARGE         = 1012,
    UPS_TIMELEFT        = 1013,
    UPS_MBATTCHG        = 1014,
    UPS_MINTIMEL        = 1015,
    UPS_MAXTIME         = 1016,
    UPS_OUTPUTV         = 1017,
    UPS_SENSE           = 1018,
    UPS_DWAKE           = 1019,
    UPS_DSHUTD          = 1020,
    UPS_LOTRANS         = 1021,
    UPS_HITRANS         = 1022,
    UPS_RETPCT          = 1023,
    UPS_ITEMP           = 1024,
    UPS_ALARMDEL        = 1025,
    UPS_BATTV           = 1026,
    UPS_LINEFREQ        = 1027,
    UPS_LASTXFER        = 1028,
    UPS_NUMXFERS        = 1029,
    UPS_TONBATT         = 1030,
    UPS_CUMONBATT       = 1031,
    UPS_XOFFBATT        = 1032,
    UPS_SELFTEST        = 1033,
    UPS_STESTI          = 1034,
    UPS_STATFLAG        = 1035,
    UPS_MANDATE         = 1036,
    UPS_SERIALNO        = 1037,
    UPS_BATTDATE        = 1038,
    UPS_NOMOUTV         = 1039,
    UPS_NOMBATTV        = 1040,
    UPS_FIRMWARE        = 1041,
    UPS_MESSAGEENT      = 1042,
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
    INV_INITIALIZING                                = 2098,
    INV_DETECTING_ISO                               = 2099,
    INV_DETECTING_IRRIDATION                        = 2100,
    INV_DETECTING_GRID                              = 2101,
    INV_STARTING                                    = 2102,
    INV_ON_GRID                                     = 2103,
    INV_ON_GRID_POWER_LIMIT                         = 2104,
    INV_ON_GRID_SELF_DERATING                       = 2105,
    INV_SHUTDOWN_FAULT                              = 2106,
    INV_SHUTDOWN_COMMAND                            = 2107,
    INV_SHUTDOWN_OVGR                               = 2108,
    INV_SHUTDOWN_COMMUNICATION_DISCONNECTED         = 2109,
    INV_POWER_LIMIT                                 = 2110,
    INV_SHUTDOWN_START_MANUALLY                     = 2111,
    INV_SHUTDOWN_DC_SWITCH_OFF                      = 2112,
    INV_GRID_DISPATCH_Q_U_CURVE                     = 2113,
    INV_NO_IRRIDATION                               = 2114,
    INV_SPOT_CHECK                                  = 2115,
    INV_SPOT_CHECKING                               = 2116,
    INV_INSPECTING                                  = 2117,
    INV_AFCI_SELF_CHECK                             = 2118,
    INV_IV_SCANNING                                 = 2119,
    INV_DC_INPUT_DETECTION                          = 2120,

    ATTR_ASSUMED_STATE                              = 3001,
    ATTR_ATTRIBUTION, 
    ATTR_AVAILABLE,
    ATTR_DEVICE_CLASS,
    ATTR_DEVICE_INFO,
    ATTR_ENTITY_CATEGORY,
    ATTR_ENTITY_PICTURE,
    ATTR_EXTRA_STATE_ATTRIBUTE,
    ATTR_HASENTITYNAME,
    ATTR_NAME,
    ATTR_SHOULDPOLL,
    ATTR_UNIQUEID,
    ATTR_ENTITY_REGISTRY_ENABLED_DEFAULT,
    ATTR_ENTITY_REGISTRY_VISIBLE_DEFAULT,
    ATTR_FORCE_UPDATE,
    ATTR_ICON,
    ATTR_ENABLED,
    ATTR_CODEFORMAT,
    ATTR_CHANGEDBY,
    ATTR_IS_ON,
    ATTR_PRESSED,
    ATTR_STATE,
    ATTR_START_DATE,
    ATTR_END_DATE,
    ATTR_IS_RECORDING,
    ATTR_IS_STREAMING,
    ATTR_MOTION_DETECTION_ENABLED,
    ATTR_BRAND,
    ATTR_MODEL,
    ATTR_FRAME_INTERVAL,
    ATTR_FRONTEND_STREAM_TYPE,
    ATTR_TEMPERATURE_UNIT,
    ATTR_PRECISION,
    ATTR_CURRENT_TEMPERATURE,
    ATTR_CURRENT_HUMIDUTY,
    ATTR_TARGET_TEMPERATURE,
    ATTR_TARGET_TEMPERATURE_HIGH,
    ATTR_TARGET_TEMPERATURE_LOW,
    ATTR_TARGET_TEMPREATURE_STEP,
    ATTR_TARGET_HUMIDITY,
    ATTR_MAX_TEMP,
    ATTR_MIN_TEMP,
    ATTR_MAX_HUMIDITY,
    ATTR_MIN_HUMIDITY,
    ATTR_HVAC_MODE,
    ATTR_HVAC_ACTION,
    ATTR_HVAC_MODES,
    ATTR_PRESET_MODE,
    ATTR_PRESET_MODES,
    ATTR_FAN_MODE,
    ATTR_FAN_MODES,
    ATTR_SWING_MODE,
    ATTR_SWING_MODES,
    ATTR_IS_AUX_HEAT,
    ATTR_SUPPORTED_FEATURES,

    ATTR_CURRENT_COVER_POSITION,
    ATTR_CURRENT_COVER_TILT_POSITION,
    ATTR_IS_OPENING,
    ATTR_IS_CLOSING,
    ATTR_IS_CLOSED,

    ATTR_SOURCE_TYPE,
    ATTR_IS_CONNECTED,
    ATTR_BATTERY_LEVEL,
    ATTR_IP_ADDRESS,
    ATTR_MAC_ADDRESS,
    ATTR_HOSTNAME,
    ATTR_LATITUDE,
    ATTR_LONGITIDE,
    ATTR_LOCATION_ACCURANCY,
    ATTR_LOCATION_NAME,

    ATTR_CURRENT_DIRECTION,
    ATTR_OSCILLATTING,
    ATTR_PERCENTAGE,
    ATTR_SPEED_COUNT,

    ATTR_AVAILABLE_MODES,
    ATTR_BRIGHTNESS,
    ATTR_COLOR_MODE,
    ATTR_COLOR_TEMP,
    ATTR_EFFECT,
    ATTR_AVAILABLE_EFFECTS,
    ATTR_HS_COLOR,
    ATTR_MAX_MIREDS,
    ATTR_MIN_MIREDS,
    ATTR_RGB_COLOR,
    ATTR_RGBW_COLOR,
    ATTR_RGBWW_COLOR,
    ATTR_SUPPORTED_COLOR_MODES,
    ATTR_WHITE_VALUE,
    ATTR_XY_COLOR,

    ATTR_CHANGED_BY,
    ATTR_CODE_FORMAT,
    ATTR_IS_LOCKED,
    ATTR_IS_LOCKING,
    ATTR_IS_UNLOCKING,
    ATTR_IS_JAMMED,

    ATTR_SOUND_MODE,
    ATTR_AVAILABLE_SOUND_MODES,
    ATTR_SOURCE,
    ATTR_SOURCES_LIST,
    ATTR_MEDIA_IMAGE_URL,
    ATTR_MEDIA_IMAGE_REMOTELY_ACCESSIBLE,
    ATTR_GROUP_MEMBERS,

    ATTR_MODE,
    ATTR_NATIVE_MAX_VALUE,
    ATTR_NATIVE_MIN_VALUE,
    ATTR_NATIVE_STEP,
    ATTR_NATIVE_VALUE,

    ATTR_CURRENT_ACTIVITY,
    ATTR_AVAILABLE_ACTIVITIES,

    ATTR_CURRENT_OPTION,
    ATTR_AVAILABLE_OPTIONS,

    ATTR_LAST_RESET,
    ATTR_NATIVE_UNIT,
    ATTR_STATE_CLASS,
    ATTR_AVAILABLE_TONES,

    ATTR_AUTO_UPDATE,
    ATTR_IN_PROGRESS,
    ATTR_INSTALLED_VERSION,
    ATTR_LATEST_VERSION,
    ATTR_RELEASE_SUMMARY,
    ATTR_RELEASE_URL,
    ATTR_TITLE,

    ATTR_BATTERY_ICON,
    ATTR_FAN_SPEED,
    ATTR_AVAILABLE_FAN_SPEEDS,
    ATTR_ERROR,

    ATTR_CURRENT_OPERATION,
    ATTR_AVAILABLE_OPERATIONS,
    ATTR_IS_AWAY_MODE_ON,

    ATTR_CONDITION,
    ATTR_NATIVE_TEMPERATURE,
    ATTR_NATIVE_TEMPERATURE_UNIT,
    ATTR_NATIVE_PRESSURE,
    ATTR_NATIVE_PRESSURE_UNIT,
    ATTR_HUMIDITY,
    ATTR_OZONE,
    ATTR_NATIVE_VISIBILITY,
    ATTR_NATIVE_VISIBILITY_UNIT,
    ATTR_NATIVE_WIND_SPEED,
    ATTR_NATIVE_WIND_SPEED_UNIT,
    ATTR_NATIVE_PRECIPITATION_UNIT,
    ATTR_WIND_BEARING,
    ATTR_FORECAST

};

enum AC_Power
{
    ACP_Off     = 0,
    ACP_On      = 1
};

enum AC_OperationMode
{
    ACOM_Auto    = 0,
    ACOM_Dry     = 1,
    ACOM_Cool    = 2,
    ACOM_Heat    = 3,
    ACOM_Fan     = 4
};

enum AC_AirSwingUD
{
    ACSUD_Auto    = -1,
    ACSUD_Up      = 0,
    ACSUD_UpMid   = 3,
    ACSUD_Mid     = 2,
    ACSUD_DownMid = 4,
    ACSUD_Down    = 1,
    ACSUD_All     = 5
};

enum AC_AirSwingLR
{
    ACSLR_Auto    = -1,
    ACSLR_Left    = 1,
    ACSLR_LeftMid = 5,
    ACSLR_Mid     = 2,
    ACSLR_RightMid= 4,
    ACSLR_Right   = 0
};

enum AC_EcoMode
{
    ACEM_Auto    = 0,
    ACEM_Powerful= 1,
    ACEM_Quiet   = 2
};

enum AC_AirSwingAutoMode
{
    ACSAM_Disabled = 1,
    ACSAM_Both     = 0,
    ACSAM_AirSwingLR = 3,
    ACSAM_AirSwingUD = 2
};

enum AC_FanSpeed
{
    ACFS_Auto        = 0,
    ACFS_Low         = 1,
    ACFS_LowMid      = 2,
    ACFS_Mid         = 3,
    ACFS_HighMid     = 4,
    ACFS_High        = 5
};

enum AC_DataMode
{
    ACDM_Day        = 0,
    ACDM_Week       = 1,
    ACDM_Month      = 2,
    ACDM_Year       = 4
};

enum AC_NanoeMode
{
    ACNM_Unavailable = 0,
    ACNM_Off         = 1,
    ACNM_On          = 2,
    ACNM_ModeG       = 3,
    ACNM_All         = 4
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

enum HyperBorgMimeTypes
{
   MIME_Attributes  = 1,    // Text payload contains key = value list
   MIME_JSON        = 2,    // Text payload contains JSON structure
   MIME_Binary      = 3
};

static QStringList MIMETypesList = {"hypeborg/attributes", "hyperborg/json", "hyperborg/binary" };

/* ============================================================= DATAPACK ====================== */

class DataPack
{
    friend class CoreServer;
    friend class UniCore;
    friend class Slotter;
    friend class HyObject;
    friend class HFS;

public:
     DataPack() 
     {
        _command = PackCommands::CommandNotDefined;
        _isText = true;

        _compressed = false;
        _socketid = 0;
     }

    DataPack(QString text)
    {
        _command = PackCommands::CommandNotDefined;
        _compressed = false;
        setText(text);
        _socketid = 0;
    }

    DataPack(QByteArray ar)
    {
        _command = PackCommands::CommandNotDefined;
        _compressed = false;
        setBinary(ar);
    }

    DataPack(const DataPack* old)
    {
        _command        = old->_command;
        _socketid       = old->_socketid;
        _isText         = old->_isText;
        _MIMEType       = old->_MIMEType;
        _text_payload   = old->_text_payload;
        _binary_payload = old->_binary_payload;
        _entityid       = old->_entityid;
        attributes      = old->attributes;
     }

    virtual ~DataPack() {}

    static int serialize(DataPack* pack)               // we fill the the block with the sended data (binary or text)
    {                                                  // we could apply format versioning here, or compressing data
        if (!pack) return 0;

        QStringList retlst;

        // We overwrite the attributes before serialization. This way if an entity would 
        // create the same value (badly behaving), it is overwritten here
        pack->attributes.insert("$$PEID", pack->_entityid);
        pack->attributes.insert("$$PSRC", pack->_source);
        pack->attributes.insert("$$PDST", pack->_destination);
        pack->attributes.insert("$$PCMD", pack->_command);

        QHashIterator<QString, QVariant> it(pack->attributes);
        while (it.hasNext())
        {
            it.next();
            retlst << QString(it.key() + "=" + it.value().toString());
        }
        pack->setText(retlst.join("\n"));
        return 1;
    }

    static int deserialize(DataPack* pack)              // we extract attributes from the text/binary data received 
    {                                                   // through socket. We could apply format versioning here or
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
            pack->_entityid = pack->attributes.value("$$PEID", "").toString();
            pack->_source = pack->attributes.value("$$PSRC", "").toString();
            pack->_destination = pack->attributes.value("$$PDST", "").toString();
            pack->_command = pack->attributes.value("$$PCMD", CommandNotDefined).toInt();
        }
        else // binary - we do not process it yet
        {
        }
         return retint;
    }

    QString textPayload()       { return _text_payload;         }
    QByteArray binaryPayload()  { return _binary_payload;       }

    bool isText()               { return _isText;               }
    QString MIMEType()          { return _MIMEType;             }
    bool compressed()           { return _compressed;           }
    QString entityId()          { return _entityid;             }
    int socketId()              { return _socketid;             }
    int command()               { return _command;              }

    QHash<QString, QVariant> attributes;

    void setSource(QString source)              { _source = source;             }
    void setDestination(QString destination)    { _destination = destination;   }
    QString source()                            { return _source;               }
    QString destination()                       { return _destination;          }

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
    int         _socketid;
    int         _command;
    QString     _entityid;
    bool        _compressed;
    bool        _isText;
    QString     _MIMEType;
    QString     _text_payload;
    QByteArray  _binary_payload;
    QString     _source;
    QString     _destination;
};

/* ======================================================== OTHER HELPER FUNCTIONS ============== */

static bool isYes(QString str)
{
    bool retbool = false;
    str = str.toUpper();
    const QStringList chk = {"YES", "1", "TRUE", "ENABLED"};
    if (chk.contains(str))
        retbool = true;
    return retbool;
}

static double convert(int from, int to, double src_val)
{
    double ret_val = src_val;
    int jidx = from*1000+to;
    if (from==to) return ret_val;

    switch(jidx)
    {
        case 1000*Farenheit+Celsius:
             ret_val=(src_val-32.0)*5.0/9.0;
            break;
        case 1000*Celsius+Farenheit:
             ret_val=src_val*1.8+32;
             break;
        case 1000*Inch+Centimeter:
            ret_val=src_val*2.54;
            break;
        case 1000*Centimeter+Inch:
            ret_val=src_val/2.54;
            break;
        case 1000*Mph+Kmh:
        case 1000*Mile+Kilometer:              // C'mon USA! Use metric system! There are 30+ kind of miles around!
            ret_val=src_val*1.609;
            break;
        case 1000*Kmh+Mph:
        case 1000*Kilometer+Mile:
            ret_val=src_val/1.609;
            break;
        case 1000*hPa+HgMM:
            ret_val=src_val*0.75006;
            break;
        case 1000*HgMM+hPa:
            ret_val=src_val*1.33322;
            break;
        case 1000*InHg+HgMM:
            ret_val=src_val*25.4;
            break;
        case 1000*HgMM+InHg:
            ret_val=src_val*0.0393701;
            break;
        case 1000*hPa+InHg:
            ret_val=src_val*0.029529983071445;
            break;
        case 1000*InHg+hPa:
            ret_val=src_val*33.863886666667;
            break;
        case 1000*Inch+Milimeter:
            ret_val=src_val*25.4;
            break;
        case 1000*Milimeter+Inch:
            ret_val=src_val*0.0393700787;
            break;
        default:
            break;
    }
    return ret_val;
}

static double hround(double in, int precision)
{
    static int pow10[5]= { 1, 10, 100, 1000, 10000 };   // Faster to execute than pow()
    precision=qBound(0, precision, 4);
    double val =in*pow10[precision];
    val = qRound(val);
    val /= pow10[precision];
    return val;
}

/* ====================== GLOBAL SEQENCE PROVIDER FOR GENERATING IDs (singleton)  =============================== */
class Sequencer
{
public:
    static Sequencer& getInstance()
    {
        static Sequencer instance;
        return instance;
    }

    Sequencer(Sequencer const&) = delete;
    void operator=(Sequencer const&) = delete;
    int getNextVal()
    {
        return _cnt++;
    }

    int setTop(int val)
    {
        if (val>_cnt)

            _cnt=val+1;
        return _cnt;
    }

private:
    Sequencer()
    {
        _cnt = 0;
    }
    int _cnt;
};

#define SEQ_NEXTVAL Sequencer::getInstance().getNextVal()























#endif