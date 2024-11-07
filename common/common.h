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
#include <QByteArray>

#define NODE_RESTART_CODE 2222

const QString HYPERBORG_VERSION         = QStringLiteral("1.0.0");
const QString HYPERBORG_BUILD_TIMESTAMP = QStringLiteral(__DATE__ " " __TIME__);

#define PATH_SEPARATOR "."
#define PATH_GLOBAL "GLOBAL"

class UniCore;
class CoreServer;
class Slotter;

typedef QPair<QString, QVariant> StackPair;
typedef QPair<QString, QVariant> Attribute;
typedef QList<Attribute> AttributeList;
typedef QHash<QString, QVariant> ParameterList;


enum HFS_Flag
{
    HFS_None            = 0,    // No flag is defined
    HFS_Method          = 1,    // Item is a method of its parents
    HFS_Attribute       = 2,    // Item is an attribute role of its parent
    HFS_LocallyCreated  = 4,    // Item is created on the local system
    HFS_RemotelyCreated = 8,    // Item is created and managed on a remote device
    HFS_LocalUsage      = 16,   // Item should only be used locally, not propagated to global
    HFS_GlobalUsage     = 32,   // Item is propagated to global matrix
    HFS_Alias           = 64,   // Item is an alias to other item
    HFS_Container       = 128,  // Item is a general container
    HFS_ArrayItem       = 256   // Item is an arrayitem
};

enum Common_State
{
    Offline             = 1,
    Online              = 2,
    Loading             = 3,
    Error               = 4
};
Q_DECLARE_METATYPE(Common_State)

enum HFS_Subscription_Flag
{
    HFSSF_NoFlag            = 0,
    HFSSF_AnyValueTrigger   = 1,    // Notification is triggered if provider updates (even if the same value is fed)
    HFSSF_AllTrigger        = 2,
    HFSSF_DoNotCreateFlow   = 4,
    HFSSF_KeyIdxDispatch    = 8
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
Q_DECLARE_METATYPE(Unit)

class HVariant
{
public:
    HVariant();
    HVariant(QVariant v, Unit u)
    {
        value = v;
        unit  = u;
    }

    QVariant value;
    Unit     unit;
};
Q_DECLARE_METATYPE(HVariant)

// Attribute defines
enum PackCommands               // SHOULD NOT INSERT NEW VALUE INTO MIDDLE, IT BREAKS ABI!!!
{
    CommandNotDefined       = -1,
    NOP                     = 0,
    Ping                    = 1,
    RegisterEntity          = 2,
    UnregisterEntity        = 3,
    RequestEntity           = 4,
    SystemEvent             = 5,
    Message                 = 6,
    SetSocketId             = 7,
    SetDevId                = 8,

    // CS
    NodeConneted            = 20,
    NodeDisconnected        = 21,

    // Flower
    JobTransfer             = 30,

    // HFS
    HFSStart                = 100,    // Range marker. Should be the same value as the _first_HFS command
    HFSDataChangeRequest    = 100,
    HFSSetData              = 101,
    HFSCreatePath           = 102,
    HFSLog                  = 103,
    HFSSubscribe            = 104,
    HFSUnsubscribe          = 105,
    HFSSetAttribute         = 106,
    HFSRemoveAttribute      = 107,
    HFSSetMethod            = 108,
    HFSRemoveMethod         = 109,

    HFSEnd                  = 109    // Range marker. Should be the same value as the _last_ HFS command
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

//enum OpenMode
//{
//    ReadOnly            = 0,
//    ReadWrite           = 1,
//    WriteOnly           = 2
//};

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

// Setting macros
#define Bootup_Name             "bootup.name"
#define Bootup_NodeRole         "bootup.role"
#define Bootup_MatixId          "bootup.matrixid"
#define Bootup_DeviceID         "bootup.deviceid"
#define Bootup_Port             "bootup.port"
#define Bootup_IP               "bootup.ip"
#define Bootup_UserName         "bootup.username"
#define Bootup_Password         "bootup.password"

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

#define CS_ConnectionState      "cs.connectionstate"            // state of the current node connection

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

enum HFSStates
{
    HFSCreated              = 0,
    HFSBootInfoLoaded       = 1,
    HFSConfigLoaded         = 2
};

constexpr auto NR_UNDECIDED = "undecided";
constexpr auto NR_MASTER = "master";
constexpr auto NR_SLAVE = "slave";

enum Attributes
{
    TEMPERATURE_9       = 100,                  // General temperatue attributes (mainly for 1-wire)
    TEMPERATURE_10      = 101,
    TEMPERATURE_11      = 102,
    TEMPERATURE_12      = 103,
    TEMPERATURE         = TEMPERATURE_9
};

enum HyperBorgMimeTypes
{
   MIME_Attributes  = 1,    // Text payload contains key = value list
   MIME_JSON        = 2,    // Text payload contains JSON structure
   MIME_Binary      = 3
};

static QStringList MIMETypesList = {"hypeborg/attributes", "hyperborg/json", "hyperborg/binary" };

static bool isYes(QString str)
{
    bool retbool = false;
    str = str.toUpper();
    const QStringList chk = {"YES", "1", "TRUE", "ENABLED", "OK", "JA"};
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

class SensorInfo
{
public:
    SensorInfo() {}
    SensorInfo(QString _key, DataType _dt, Unit _unit = NotDefined, int _precision = 5, int _scale = 2)
    {
        key         = _key;
        datatype    = _dt;
        unit        = _unit;
        precision   = _precision;
        scale       = _scale;
    }

    QString key;
    DataType datatype;
    Unit unit;

    int precision;
    int scale;

};

static double hround(double in, int precision)
{
    static int pow10[5]= { 1, 10, 100, 1000, 10000 };   // Faster to execute than pow()
    precision=qBound(0, precision, 4);
    double val =in*pow10[precision];
    val = qRound(val);
    val /= pow10[precision];
    return val;
}

static bool splitKeyAndVal(QString src, QString& key, QString& val)
{
    QStringList wsl = src.split("=");
    if (wsl.count() == 2)
    {
        key = wsl.at(0);
        val = wsl.at(1);
        return true;
    }
    return false;
}


#endif 
