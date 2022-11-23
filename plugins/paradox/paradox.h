#ifndef Paradox_H
#define Paradox_H

#include <QObject>
#include <QtPlugin>
#include <QString>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QTimer>
#include <QDebug>
#include <QByteArray>
#include <QDateTime>
#include <QTranslator>
#include <QHash>

#include "common.h"
#include <hyplugin.h>
#include <hyobject.h>

enum Maxes
{
    NumberOfAreas = 0,
    NumberOfZones = 1,
    NumberOfUsers = 2,
    LAST_MAXES	  = 3
};

enum EventGroup
{
    EG_ZoneIsOk 			= 0,
    EG_ZoneIsOpen			= 1,
    EG_ZoneIsTampered			= 2,
    EG_ZoneIsInFireLoopTrouble		= 3,
    EG_NonReportableEvent		= 4,
    EG_UserCodeEnteredOnKeypad 		= 5,
    EG_UserCardAccessOnDoor		= 6,
    EG_BypassProgrammingAccess		= 7,
    EG_TXDelayZoneAlarm			= 8,
    EG_ArmingWithMaster			= 9,
    EG_ArmingWithUserCode		= 10,
    EG_ArmingWithKeySwitch		= 11,
    EG_SpecialArming			= 12,
    EG_DisarmWithMaster			= 13,
    EG_DisarmWithUserCode		= 14,
    EG_DisarmWithKeySwitch		= 15,
    EG_DisarmAfterAlarmWithMaster	= 16,
    EG_DisarmAfterAlarmWithUserCode	= 17,
    EG_DisarmAfterAlarmWithKeyswitch	= 18,
    EG_AlarmCancelledWithMaster		= 19,
    EG_AlarmCancelledWithUserCode	= 20,
    EG_AlarmCancelledWithKeySwith	= 21,
    EG_SpecialDisarm			= 22,
    EG_ZoneBypassed			= 23,
    EG_ZoneInAlarm			= 24,
    EG_FireAlarm			= 25,
    EG_ZoneAlarmRestore			= 26,
    EG_FireAlarmRestore			= 27,
    EG_EarlyToDisarmByUser		= 28,
    EG_LateToDisarmByUser		= 29,
    EG_SpecialAlarm			= 30,
    EG_DuressAlarmByUser		= 31,
    EG_ZoneShutdown			= 32,
    EG_ZoneTamper			= 33,
    EG_ZoneTamperRestore		= 34,
    EG_SpecialTamper			= 35,
    EG_TroubleEvent			= 36,
    EG_TroubleRestore			= 37,
    EG_ModuleTrouble			= 38,
    EG_ModuleTroubleRestore		= 39,
    EG_FailToCommunuicateOnTelephone	= 40,
    EG_LowBatteryOnZone			= 41,
    EG_ZoneSupervisionTrouble		= 42,
    EG_LowBatteryOnZoneRestored		= 43,
    EG_ZoneSupervisionTroubleRestored	= 44,
    EG_SpecialEvents			= 45,
    EG_EarlyToArmByUser			= 46,
    EG_LateToArmByUser			= 47,
    EG_UtilityKey			= 48,
    EG_RequestForExit			= 49,
    EG_AccessDenied			= 50,
    EG_DoorLeftOpenAlarm		= 51,
    EG_DoorForcedAlarm			= 52,
    EG_DoorLeftOpenRestore		= 53,
    EG_DoorForcedOpenRestore		= 54,
    EG_IntellizoneTriggered		= 55,
    EG_NewModuleAssignedOnCombus	= 58,
    EG_ModuleManuallyRemovedFromCombus	= 59,
    EG_AccessGrantedToUser		= 62,
    EG_AccessDeniedToUser		= 63,
    EG_Status1				= 64,
    EG_Status2				= 65,
    EG_Status3				= 66
};

enum NonReportableEvent	// Group:4
{
    NRE_TLMTrouble			= 0,
    NRE_SmokeDetectorReset		= 1,
    NRE_ArmWithNoEntryDelay		= 2,
    NRE_ArmInStayMode			= 3,
    NRE_ArmInAwayMode			= 4,
    NRE_FullArmWhenInStayMode		= 5,
    NRE_VoiceModuleAccess		= 6,
    NRE_RemoteControlAcces		= 7,
    NRE_PCFailToCommunicate		= 8,
    NRE_Midnight			= 9,
    NRE_NEWareUserLogin			= 10,
    NRE_NEWareUserLogout		= 11,
    NRE_UserInitiatedCallUp		= 12,
    NRE_ForceAnswer			= 13,
    NRE_ForceHangup			= 14
};

enum SpecialArming	// Group:12
{
    SA_AutoArming			= 0,
    SA_ArmingByWinLoad			= 1,
    SA_LateToClose			= 2,
    SA_NoMovementArming			= 3,
    SA_PartialArming			= 4,
    SA_OneTouchArming			= 5,
    SA_FutureUse1			= 6,
    SA_FutureUse2			= 7,
    SA_VoiceModuleArming		= 8
};

enum SpecialDisarm
{
    SD_AutoArmCancelled			= 0,
    SD_OneTouchStayOrInstantDisarm	= 1,
    SD_DisarmingWithWinLoad		= 2,
    SD_DisarmingWithWinLoadAfterAlarm	= 3,
    SD_WinLoadCancelledAlarm		= 4,
    SD_FutureUse1			= 5,
    SD_FutureUse2			= 6,
    SD_FutureUse3			= 7,
    SD_VoiceModuleDisarming		= 8
};

enum SpecialAlarming
{
    SPA_EmergencyPanic			= 0,
    SPA_MedicalPanic			= 1,
    SPA_FirePanic			= 2,
    SPA_RecentClosing			= 3,
    SPA_PoliceCode			= 4,
    SPA_GlobalShutdown			= 5
};

enum Troubles
{
    TRB_TLMTrouble			= 0,
    TRB_ACFailure			= 1,
    TRB_BatteryFailure			= 2,
    TRB_AUXCurrentLimit			= 3,
    TRB_BellCurrentLimit		= 4,
    TRB_BellAbsent			= 5,
    TRB_ClockTrouble			= 6,
    TRB_GlobalFireLoop			= 7
};

enum ModuleTroubles
{
    MTRB_CombusFault			= 0,
    MTRB_ModuleTamper			= 1,
    MTRB_ROMRAMError			= 2,
    MTRB_TLMTrouble			= 3,
    MTRB_FailToCommunicate		= 4,
    MTRB_PrinterFault			= 5,
    MTRB_ACFailure			= 6,
    MTRB_BatteryFailure			= 7,
    MTRB_AUXFailire			= 8
};

enum SpecialEvents
{
    SE_PowerUpAfterTotalPowerDown	= 0,
    SE_SoftwareResetWatchdog		= 1,
    SE_TestReport			= 2,
    SE_FutureUse			= 3,
    SE_WinLoadConnected			= 4,
    SE_WinLoadDisconnected		= 5,
    SE_InstallerInProgramming		= 6,
    SE_InstellerOutProgramming		= 7    
};

enum ModuleAssign
{
    MA_ModuleAddress			= 0,
    MA_AnyModule			= 255
};

enum Status1
{
    S1_Armed				= 0,
    S1_ForceArmed			= 1,
    S1_StayArmed			= 2,
    S1_InstantArmed			= 3,
    S1_StrobeAlarm			= 4,
    S1_SilentAlarm			= 5,
    S1_AudibleAlarm			= 6,
    S1_FireAlarm			= 7
};

enum Status2
{
    S2_Ready				= 0,
    S2_ExitDelay			= 1,
    S2_EntryDelay			= 2,
    S2_SystemInTrouble			= 3,
    S2_AlarmInMemory			= 4,
    S2_ZonesBypassed			= 5,
    S2_InstallerProgramming		= 6,
    S2_KeypadLockout			= 7
};

enum Status3
{
    S3_IntellizoneDelayEngaged		= 0,
    S3_FireDelayEngaged			= 1,
    S3_AutoArm				= 2,
    S3_ArmingWithVoiceModule		= 3,
    S3_Tamper				= 4,
    S3_ZoneLowBattery			= 5,
    S3_FireLoopTrouble			= 6,
    S3_ZoneSupervisionTrouble		= 7
};

class Paradox : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "paradox.json");
    Q_INTERFACES(HyPluginInterface);

public:
    Paradox(QObject *parent=NULL) : HyPluginInterface(), HyObject(parent)
    {
        port = NULL;
        sysenabled = false;
        for (int i=0;i<Maxes::LAST_MAXES;i++) maxes.append(0);
        QObject::connect(&totimer, SIGNAL(timeout()), this, SLOT(timeout()));
        totimer.setSingleShot(true);
        totimer.start(1000);
        QObject::connect(&sendtimer, SIGNAL(timeout()), this, SLOT(sendQueue()));
    }

    ~Paradox() 
    {
        if (port) port->close();
        qDebug() << "port closed";
    }

    QString name()          { return "paradox";                         }
    QString description()   { return "Paradox PTR3 ASCII Converter";    }
    int implementation()    { return Developement;                      }
    QObject *getObject()    { return this;                              }
    QString author()        { return "Imre, Nagy  <i@hyperborg.com>";   }

    void init()             {}

signals:
    void zoneStatusChanged(int group, int area, int zone);

private slots:
    void timeout();
    void initConnection();
    void testStatus();

    void sendQueue();
    void writeData(QString str);
    void readyRead();

    void processIncomingEvent(QString str);
    void processSysEvent(QString str);

    void switchVirtualInput(int index, bool open);

    QString getGroupDescription(int gidx);
    bool hasSubEvent(int gidx);
    QString getEventDescription(int gidx, int eidx);

    QString requestZoneStatus(int index);
    QString requestAreaStatus(int index);
    QString requestAreaLabel(int index);
    QString requestZoneLabel(int index);
    QString requestUserLabel(int index);
    QString intToStr(int idx, int totallength=3);

    void syncToCenter();
    void addSendQueue(QString str);
    void testSendQueue();

private:
    QList<int> maxes;
    QTimer totimer;
    QTimer sendtimer;
    QSerialPort *port;
    QString readbuffer;
    int pcnt;

    QStringList sendqueue;
    QHash<QString, QString> usernames;
    QHash<QString, QString> areanames;
    QStringList areas;
    QHash<QString, QString> zonenames;
    QStringList zones;
    bool sysenabled;

};
#endif