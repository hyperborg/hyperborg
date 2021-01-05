#include <paradox.h>

void Paradox::timeout()
{
    initConnection();
    testStatus();
}

void Paradox::initConnection()
{
    pcnt=0;
    port = new QSerialPort("/dev/ttyUSB0", this);
    port->setBaudRate(QSerialPort::Baud57600);
    port->setFlowControl(QSerialPort::SoftwareControl);
    port->setDataBits(QSerialPort::Data8);
    port->setParity(QSerialPort::NoParity);
    port->setStopBits(QSerialPort::OneStop);

    if (port->open(QIODevice::ReadWrite))
    {
	qDebug() << "port opened";
	bool f = connect(port, SIGNAL(readyRead()), this, SLOT(readyRead()));
	qDebug() << "interconnect :" << f;
	port->clear();
	syncToCenter();
    }
    else
    {
	qDebug() << "port open failed";
    }

}

void Paradox::testStatus()
{
}

void Paradox::writeData(QString str)
{
//    qDebug() << "WRITE: " << str << " PORT: " << port;
    port->write(str.toLatin1());
    port->flush();
}

void Paradox::readyRead()
{
//    qDebug() << "======================================== [" << port->bytesAvailable() << "] ===========";
    QDateTime dt;
    dt=QDateTime::currentDateTime();

    while (port->bytesAvailable()>0)
    {
	readbuffer.append(QString(port->readAll()));
    }

    QStringList cmdlst;

    int lindex=readbuffer.lastIndexOf("\r");
    if (lindex>-1)
    {
	QString wa=readbuffer.left(lindex);
	readbuffer=readbuffer.right(readbuffer.length()-lindex-1);
	cmdlst=wa.split("\r");
    }

    for (int i=0;i<cmdlst.count();i++)
    {
	processIncomingEvent(cmdlst.at(i));
    }
}

void Paradox::switchVirtualInput(int idx, bool open)
{
    Q_UNUSED(idx);
    Q_UNUSED(open);
}

void Paradox::addSendQueue(QString str)
{
    sendqueue.append(str);
    testSendQueue();
}

void Paradox::testSendQueue()
{
    sendtimer.stop();
    if (sendqueue.count())
	sendtimer.start(10);
}

void Paradox::sendQueue()
{
    if (sendqueue.count())
	writeData(sendqueue.takeFirst());
    testSendQueue();
}

QString Paradox::intToStr(int idx, int totallength)
{
    QString str = QString::number(idx);
    while (str.length()<totallength) str.prepend("0");
    return str;
}

QString Paradox::requestAreaStatus(int idx)
{
    QString str;
    str = "RZ"+intToStr(idx)+"\r";
    return str;
}

QString Paradox::requestZoneStatus(int idx)
{
    QString str;
    str = "RZ"+intToStr(idx)+"\r";
    return str;
}

QString Paradox::requestAreaLabel(int idx)
{
    QString str;
    str = "AL"+intToStr(idx)+"\r";
    return str;
}

QString Paradox::requestZoneLabel(int idx)
{
    QString str;
    str = "ZL"+intToStr(idx)+"\r";
    return str;
}

QString Paradox::requestUserLabel(int idx)
{
    QString str;
    str = "UL"+intToStr(idx)+"\r";
    return str;
}

void Paradox::syncToCenter()
{
    sysenabled = false;
    maxes[NumberOfUsers] = 999;
    maxes[NumberOfAreas] = 8;
    maxes[NumberOfZones]= 192;

    usernames.clear();
    areanames.clear();
    areas.clear();
    zonenames.clear();
    zones.clear();

    for (int i=1;i<maxes[NumberOfUsers];i++)
    addSendQueue(requestUserLabel(i));

    for (int i=1;i<maxes[NumberOfAreas];i++)
    addSendQueue(requestAreaLabel(i));

    for (int i=1;i<maxes[NumberOfZones];i++)
    addSendQueue(requestZoneLabel(i));

    addSendQueue(requestUserLabel(0));	
}


void Paradox::processIncomingEvent(QString str)
{
//    qDebug() << "SYSEVENT: " << str;
    if (str.mid(0,1)=="G")
    {
	processSysEvent(str);
    }
    else
    {
	QString cmd=str.mid(0,2);
	if (cmd=="RA")		// Request Area status
	{
	    
        }
	else if (cmd=="RZ")		// Request Zone status
	{
	    qDebug() << "ZONE STATUS: " <<str;
	}
	else if (cmd=="ZL")		// Request Zone label
	{
	    if (!str.mid(3,str.length()-3).isEmpty())
	    {
		QString code = str.mid(2,3);
		QString name = str.mid(5).simplified();
		if (!name.isEmpty() && name.mid(0,4)!="Zone")
		{
		    zones.append(code);
		    zonenames.insert(code, name);
		    qDebug() << "ZONE LABEL: " << code << " " << name;
		}
	    }
        }
	else if (cmd=="AL")		// Request Area label
	{
	    if (!str.mid(3,str.length()-3).isEmpty())
	    {
		QString code = str.mid(2,3);
		QString name = str.mid(5).simplified();
		if (!name.isEmpty() && name.mid(0,4)!="Area")
		{
		    areas.append(code);
		    areanames.insert(code, name);
		    qDebug() << "AREA LABEL: " << code << " " << name;
		}
	    }
	}
	else if (cmd=="UL")		// Request User label
	{
	    if (!str.contains("User Code") && !str.contains(" Code "))
	    {
		QString code = str.mid(2,3);
		QString name = str.mid(5).simplified();
		if (code!="000")
		{
		    qDebug() << "Register user: " << code << " " << name;
		    usernames.insert(code, name);
		}
	    }
	    if (str.mid(0,5)=="UL000") sysenabled = true;
	}
	else
	{
	    cmd=str.mid(0,3);
	    if (cmd=="PGM")		// Virtual PGM event
	    {
	    }
	}
    }
}

void Paradox::processSysEvent(QString str)
{
    if (!sysenabled) return;
    QString cmd = str.mid(0,1);
    QString npr = str.mid(4,1);
    QString apr = str.mid(8,1);
    if (cmd!="G" || npr!="N" || apr!="A")
    {
	qDebug() << "SYSEVENT FORMAT ERROR :" << str;
    }

    QString groupstr = str.mid(1,3);
    QString eventstr = str.mid(5,3);
    QString areastr  = str.mid(9,3);

    bool ok;
    int group = groupstr.toInt(&ok);
    int event = eventstr.toInt(&ok);
    int area  = areastr.toInt(&ok);

    QString outstr = getGroupDescription(group);
    if (hasSubEvent(group))
	outstr +="  "+getEventDescription(group, event);
    outstr+=" AREA: "+ areanames.value(areastr);
    outstr+=" ZONE: "+ zonenames.value(eventstr);

    qDebug() << "SYSEVENT : " << outstr;
    emit zoneStatusChanged(group, area, event);

}

bool Paradox::hasSubEvent(int gidx)
{
    bool rv=false;
    if (gidx==EG_NonReportableEvent 	||
	gidx==EG_SpecialArming      	||
        gidx==EG_SpecialDisarm	    	||
	gidx==EG_SpecialAlarm       	||
	gidx==EG_TroubleEvent       	||
	gidx==EG_TroubleRestore     	||
	gidx==EG_ModuleTrouble   	||
	gidx==EG_ModuleTroubleRestore 	||
	gidx==EG_SpecialEvents	    	||
	gidx==EG_Status1	    	||
	gidx==EG_Status2	    	||
	gidx==EG_Status3	      
	)
    {
	rv=true;
    }
    return rv;
}

QString Paradox::getGroupDescription(int gidx)
{
    QString retstr;
    switch(gidx)
    {
        case EG_ZoneIsOk:			retstr=tr("Zone is OK");			break;
        case EG_ZoneIsOpen:			retstr=tr("Zone is OPEN");			break;
        case EG_ZoneIsTampered:			retstr=tr("Zone is TAMPERED");			break;
        case EG_ZoneIsInFireLoopTrouble:	retstr=tr("Zone is in FireLoop trouble");	break;
        case EG_NonReportableEvent:		retstr=tr("Non-reportable event");		break;
        case EG_UserCodeEnteredOnKeypad:	retstr=tr("User code entered on keypad");	break;
        case EG_UserCardAccessOnDoor:		retstr=tr("User or card access on door");	break;
        case EG_BypassProgrammingAccess:	retstr=tr("Bypass programming access");		break;
        case EG_TXDelayZoneAlarm:		retstr=tr("TX Delay Zone Alarm");		break;
        case EG_ArmingWithMaster:		retstr=tr("Arming with master");		break;
        case EG_ArmingWithUserCode:		retstr=tr("Arming with user code");		break;
        case EG_ArmingWithKeySwitch:		retstr=tr("Arming with keyswitch");		break;
        case EG_SpecialArming:			retstr=tr("Special arming");			break;
        case EG_DisarmWithMaster:		retstr=tr("Disarm with master");		break;
        case EG_DisarmWithUserCode:		retstr=tr("Disarm with user code");		break;
        case EG_DisarmWithKeySwitch:		retstr=tr("Disarm with keyswitch");		break;
        case EG_DisarmAfterAlarmWithMaster:	retstr=tr("Disarm after alarm with master");	break;
        case EG_DisarmAfterAlarmWithUserCode:	retstr=tr("Disarm after alarm with usercode");	break;
        case EG_DisarmAfterAlarmWithKeyswitch:	retstr=tr("Disarm after alarm with keyswitch");	break;
        case EG_AlarmCancelledWithMaster:	retstr=tr("Alarm cancelled with master");	break;
        case EG_AlarmCancelledWithUserCode:	retstr=tr("Alarm cancelled with usercode");	break;
        case EG_AlarmCancelledWithKeySwith:	retstr=tr("Alarm cancelled with keyswitch");	break;
        case EG_SpecialDisarm:			retstr=tr("Special disarm ");			break;
        case EG_ZoneBypassed:			retstr=tr("Zone bypassed");			break;
        case EG_ZoneInAlarm:			retstr=tr("Zone in alarm");			break;
        case EG_FireAlarm:			retstr=tr("Fire alarm");			break;
        case EG_ZoneAlarmRestore:		retstr=tr("Zone alarm restore");		break;
        case EG_FireAlarmRestore:		retstr=tr("Fire alarm restore");		break;
        case EG_EarlyToDisarmByUser:		retstr=tr("Early to disarm by user");		break;
        case EG_LateToDisarmByUser:		retstr=tr("Late to disarm by user");		break;
        case EG_SpecialAlarm:			retstr=tr("Special alarm")		;	break;
        case EG_DuressAlarmByUser:		retstr=tr("Duress alarm by user");		break;
        case EG_ZoneShutdown:			retstr=tr("Zone shutdown");			break;
        case EG_ZoneTamper:			retstr=tr("Zone tamper");			break;
        case EG_ZoneTamperRestore:		retstr=tr("Zone tamper restore");		break;
        case EG_SpecialTamper:			retstr=tr("Special tamper");			break;
        case EG_TroubleEvent:			retstr=tr("Trouble event");			break;
        case EG_TroubleRestore:			retstr=tr("Trouble restore");			break;
        case EG_ModuleTrouble:			retstr=tr("Module trouble");			break;
        case EG_ModuleTroubleRestore:		retstr=tr("Module trouble restore");		break;
        case EG_FailToCommunuicateOnTelephone:	retstr=tr("Fail to communicate over telephone");break;
        case EG_LowBatteryOnZone:		retstr=tr("Low battery on zone");		break;
        case EG_ZoneSupervisionTrouble:		retstr=tr("Zone supervision trouble");		break;
        case EG_LowBatteryOnZoneRestored:	retstr=tr("Low battery on zone restored");	break;
        case EG_ZoneSupervisionTroubleRestored:	retstr=tr("Zone supervision trouble restored");	break;
        case EG_SpecialEvents:			retstr=tr("Special events");			break;
        case EG_EarlyToArmByUser:		retstr=tr("Early to arm by user");		break;
        case EG_LateToArmByUser:		retstr=tr("Late to arm by user");		break;
        case EG_UtilityKey:			retstr=tr("Utility key");			break;
        case EG_RequestForExit:			retstr=tr("Request for exit");			break;
        case EG_AccessDenied:			retstr=tr("Access denied");			break;
        case EG_DoorLeftOpenAlarm:		retstr=tr("Door left open alarm");		break;
        case EG_DoorForcedAlarm:		retstr=tr("Door forced alarm");			break;
        case EG_DoorLeftOpenRestore:		retstr=tr("Door left open restore");		break;
        case EG_DoorForcedOpenRestore:		retstr=tr("Door forces open restore");		break;
        case EG_IntellizoneTriggered:		retstr=tr("Intellizone triggered");		break;
        case EG_NewModuleAssignedOnCombus:	retstr=tr("New module is assigned to combus");	break;
        case EG_ModuleManuallyRemovedFromCombus:retstr=tr("Module manually removed from combus");break;
        case EG_AccessGrantedToUser:		retstr=tr("Access granted to user");		break;
        case EG_AccessDeniedToUser:		retstr=tr("Access denied to user");		break;
        case EG_Status1:			retstr=tr("Status 1");				break;
        case EG_Status2:			retstr=tr("Status 2");				break;
        case EG_Status3:			retstr=tr("Status 3");				break;
    	    default:
    	retstr=tr("Unknown group");
    }
    return retstr;
}

QString Paradox::getEventDescription(int gidx, int eidx)
{
    QString retstr;
    switch(gidx)
    {
	case EG_NonReportableEvent:
	    {
		switch(eidx)
		{
		    case NRE_TLMTrouble:		retstr=tr("TLM trouble");		break;
    		    case NRE_SmokeDetectorReset:	retstr=tr("Smoke detector reset");	break;
    		    case NRE_ArmWithNoEntryDelay:	retstr=tr("Arm with no entry delay");	break;
    		    case NRE_ArmInStayMode:		retstr=tr("Arm in stay mode");		break;
    		    case NRE_ArmInAwayMode:		retstr=tr("Arm in away mode");		break;
    		    case NRE_FullArmWhenInStayMode:	retstr=tr("Full arm when in stay mode");break;
    		    case NRE_VoiceModuleAccess:		retstr=tr("Voice module access");	break;
    		    case NRE_RemoteControlAcces:	retstr=tr("Remote control acces");	break;
    		    case NRE_PCFailToCommunicate:	retstr=tr("PC fail to communicate");	break;
    		    case NRE_Midnight:			retstr=tr("Midnight");			break;
    		    case NRE_NEWareUserLogin:		retstr=tr("NEWare user login");		break;
    		    case NRE_NEWareUserLogout:		retstr=tr("NEWare user logout");	break;
    		    case NRE_UserInitiatedCallUp:	retstr=tr("USer initiated callup");	break;
    		    case NRE_ForceAnswer:		retstr=tr("Force answer");		break;
    		    case NRE_ForceHangup:		retstr=tr("Force hangup");		break;
		}
	    }
	    break;

	case EG_SpecialArming:
	    {
		switch(eidx)
		{
    		    case SA_AutoArming:			retstr=tr("Auto arming");		break;
    		    case SA_ArmingByWinLoad:		retstr=tr("Arming by WinLoad");		break;
    		    case SA_LateToClose:		retstr=tr("Late to close");		break;
    		    case SA_NoMovementArming:		retstr=tr("No movement arming");	break;
    		    case SA_PartialArming:		retstr=tr("Partial arming");		break;
    		    case SA_OneTouchArming:		retstr=tr("One-touch arming");		break;
    		    case SA_FutureUse1:			retstr=tr("Future use 1");		break;
    		    case SA_FutureUse2:			retstr=tr("Future use 2");		break;
    		    case SA_VoiceModuleArming:		retstr=tr("Voice module arming");	break;
		}
	    }
	    break;

        case EG_SpecialDisarm:
	    {
		switch(eidx)
		{
    		    case SD_AutoArmCancelled:		retstr=tr("Auto arm cancelled");			break;
    		    case SD_OneTouchStayOrInstantDisarm:retstr=tr("One-touch stay or instant disarm");		break;
    		    case SD_DisarmingWithWinLoad:	retstr=tr("Disarming with WinLoad");			break;
    		    case SD_DisarmingWithWinLoadAfterAlarm:	retstr=tr("Disarming with WinLoad after alarm");break;
    		    case SD_WinLoadCancelledAlarm:	retstr=tr("WinLoad cancelled alarm");			break;
    		    case SD_FutureUse1:			retstr=tr("Future use 1");				break;
    		    case SD_FutureUse2:			retstr=tr("Future use 2");				break;
    		    case SD_FutureUse3:			retstr=tr("Future use 3");				break;
    		    case SD_VoiceModuleDisarming:	retstr=tr("Voice module disarming");			break;
		}
	    }
	    break;

	case EG_SpecialAlarm:
	    {
		switch(eidx)
		{
    		    case SPA_EmergencyPanic:		retstr=tr("Emergeny panic");	break;
    		    case SPA_MedicalPanic:		retstr=tr("Medical panic");	break;
    		    case SPA_FirePanic:			retstr=tr("Fire panic");	break;
    		    case SPA_RecentClosing:		retstr=tr("Recent closing");	break;
    		    case SPA_PoliceCode:		retstr=tr("Police ocde");	break;
    		    case SPA_GlobalShutdown:		retstr=tr("Global shutdown");	break;	
		}
	    }
	    break;

	case EG_TroubleEvent:
	    {
		switch(eidx)
		{
    		    case TRB_TLMTrouble:		retstr=tr("TLM trouble");		break;
    		    case TRB_ACFailure:			retstr=tr("AC failure");		break;
    		    case TRB_BatteryFailure:		retstr=tr("Battery failure");		break;
    		    case TRB_AUXCurrentLimit:		retstr=tr("AUX current limit");		break;
    		    case TRB_BellCurrentLimit:		retstr=tr("BELL current limit");	break;
    		    case TRB_BellAbsent:		retstr=tr("Bell absent");		break;
    		    case TRB_ClockTrouble:		retstr=tr("Clock trouble");		break;
    		    case TRB_GlobalFireLoop:		retstr=tr("Global fire loop");		break;
		}
	    }
	    break;

	case EG_TroubleRestore:
	    {
		switch(eidx)
		{
    		    case TRB_TLMTrouble:		retstr=tr("TLM trouble");		break;
    		    case TRB_ACFailure:			retstr=tr("AC failure");		break;
    		    case TRB_BatteryFailure:		retstr=tr("Battery failure");		break;
    		    case TRB_AUXCurrentLimit:		retstr=tr("AUX current limit");		break;
    		    case TRB_BellCurrentLimit:		retstr=tr("BELL current limit");	break;
    		    case TRB_BellAbsent:		retstr=tr("Bell absent");		break;
    		    case TRB_ClockTrouble:		retstr=tr("Clock trouble");		break;
    		    case TRB_GlobalFireLoop:		retstr=tr("Global fire loop");		break;
		}
	    }
	    break;

	case EG_ModuleTrouble:
	    {
		switch(eidx)
		{
    		    case MTRB_CombusFault:		retstr=tr("Combus fault");		break;
    		    case MTRB_ModuleTamper:		retstr=tr("Module tamper");		break;
    		    case MTRB_ROMRAMError:		retstr=tr("ROM/RAM error");		break;
    		    case MTRB_TLMTrouble:		retstr=tr("TLM trouble");		break;
    		    case MTRB_FailToCommunicate:	retstr=tr("Fail to communicate");	break;
    		    case MTRB_PrinterFault:		retstr=tr("Printer fault");		break;
    		    case MTRB_ACFailure:		retstr=tr("AC Failure");		break;
    		    case MTRB_BatteryFailure:		retstr=tr("Battery failure");		break;
    		    case MTRB_AUXFailire:		retstr=tr("AUX failure");		break;
		}
	    }
	    break;

	case EG_ModuleTroubleRestore:
	    {
		switch(eidx)
		{
    		    case MTRB_CombusFault:		retstr=tr("Combus fault");		break;
    		    case MTRB_ModuleTamper:		retstr=tr("Module tamper");		break;
    		    case MTRB_ROMRAMError:		retstr=tr("ROM/RAM error");		break;
    		    case MTRB_TLMTrouble:		retstr=tr("TLM trouble");		break;
    		    case MTRB_FailToCommunicate:	retstr=tr("Fail to communicate");	break;
    		    case MTRB_PrinterFault:		retstr=tr("Printer fault");		break;
    		    case MTRB_ACFailure:		retstr=tr("AC Failure");		break;
    		    case MTRB_BatteryFailure:		retstr=tr("Battery failure");		break;
    		    case MTRB_AUXFailire:		retstr=tr("AUX failure");		break;
		}
	    }
	    break;

	case EG_SpecialEvents:
	    {
		switch(eidx)
		{
    		    case SE_PowerUpAfterTotalPowerDown:	retstr=tr("Power up after total power down");		break;
    		    case SE_SoftwareResetWatchdog:	retstr=tr("Software reset watchdog");	break;
    		    case SE_TestReport:			retstr=tr("Test report");		break;
    		    case SE_FutureUse:			retstr=tr("Future use");		break;
    		    case SE_WinLoadConnected:		retstr=tr("WinLoad connected");		break;
    		    case SE_WinLoadDisconnected:	retstr=tr("WinLoad disconnected");	break;
    		    case SE_InstallerInProgramming:	retstr=tr("Installer in programming");	break;
    		    case SE_InstellerOutProgramming:	retstr=tr("Installer out programming");	break;
		}
	    }
	    break;

	case EG_Status1:
	    {
		switch(eidx)
		{
    		    case S1_Armed:			retstr=tr("Armed");			break;
    		    case S1_ForceArmed:			retstr=tr("Force armed");		break;
    		    case S1_StayArmed:			retstr=tr("Stay armed");		break;
    		    case S1_InstantArmed:		retstr=tr("Instant armed");		break;
    		    case S1_StrobeAlarm:		retstr=tr("Strobe alarm");		break;
    		    case S1_SilentAlarm:		retstr=tr("Silent alarm");		break;
    		    case S1_AudibleAlarm:		retstr=tr("Audible alarm");		break;
    		    case S1_FireAlarm:			retstr=tr("Fire alarm");		break;
		}
	    }
	    break;

	case EG_Status2:
	    {
		switch(eidx)
		{
    		    case S2_Ready:			retstr=tr("Ready");			break;
    		    case S2_ExitDelay:			retstr=tr("Exit delay");		break;
    		    case S2_EntryDelay:			retstr=tr("Entry delay");		break;
    		    case S2_SystemInTrouble:		retstr=tr("System in trouble");		break;
    		    case S2_AlarmInMemory:		retstr=tr("Alarm in memory");		break;
    		    case S2_ZonesBypassed:		retstr=tr("Zones bypassed");		break;
    		    case S2_InstallerProgramming:	retstr=tr("Installer programming");	break;
    		    case S2_KeypadLockout:		retstr=tr("Keypad lockout");		break;
		}
	    }
	    break;

	case EG_Status3:
	    {
		switch(eidx)
		{
    		    case S3_IntellizoneDelayEngaged:	retstr=tr("Inteliizone delay engaged");	break;
    		    case S3_FireDelayEngaged:		retstr=tr("Fire delay engaged");	break;
    		    case S3_AutoArm:			retstr=tr("Auto arm");			break;
    		    case S3_ArmingWithVoiceModule:	retstr=tr("Arming with voice module");	break;
    		    case S3_Tamper:			retstr=tr("Tamper");			break;
    		    case S3_ZoneLowBattery:		retstr=tr("Zone low battery");		break;
    		    case S3_FireLoopTrouble:		retstr=tr("Fire loop trouble");		break;
    		    case S3_ZoneSupervisionTrouble:	retstr=tr("Zone supervision trouble");	break;
		}
	    }
	    break;
	}
    return retstr;
}