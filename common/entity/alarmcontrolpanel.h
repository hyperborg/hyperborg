#ifndef AlarmControlPanelENTITY_H
#define AlarmControlPanelENTITY_H

#include "entity.h"

class AlarmControlPanelEntity : public Entity
{
    Q_OBJECT
public:
    AlarmControlPanelEntity(QObject *parent=NULL);
    ~AlarmControlPanelEntity();

    QString state() 			{ return QString(); }
    QString codeFormat() 		{ return QString(); }
    QString changedBy()			{ return QString(); }


};

#endif

/*

STATES

    "disarmed"		- The alarm is disarmed (off).
    "armedHome"		- The alarm is armed in home mode.
    "armedAway"		- The alarm is armed in away mode.
    "armedNght"		- The alarm is armed in night mode.
    "armedVcation"	- The alarm is armed in vacation mode.
    "armedCustomBypass"	- The alarm is armed in bypass mode.
    "pending"		- The alarm is pending (towards triggered).
    "arming"		- The alarm is arming.
    "disarming"		- The alarm is disarming.
    "triggered"		- The alarm is triggered.

FATURES

    armAway		- The alarm supports arming in away mode.
    armCustomBypass	- The alarm supports arming with a bypass.
    armHome		- The alarm supports arming in home mode.
    armNightT		- The alarm supports arming in night mode.
    armVacation		- The alarm supports arming in vacation mode.
    remoteTrigger	- The alarm can be triggered remotely.

CODE FORMATS

    "none"		- No code required.
    "number"		- Code is a number (Shows ten-key pad on frontend).
    "text"		- Code is a string.

*/