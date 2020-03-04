/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ALARM_CONTROL_PANEL_H
#define ALARM_CONTROL_PANEL_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class alarm_control_panel : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "alarm_control_panel.json");
    Q_INTERFACES(HyPluginInterface);
public:
    alarm_control_panel();
    ~alarm_control_panel();

    QString name() 		{ return "alarm_control_panel"; }
    QString description()	{ return "Component to interface with an alarm control panel."; }

protected:
    	void  async_setup();
	void  async_setup_entry();
	void  async_unload_entry();
	void code_format();
	void changed_by();
	void code_arm_required();
	void alarm_disarm();
	void  async_alarm_disarm();
	void alarm_arm_home();
	void  async_alarm_arm_home();
	void alarm_arm_away();
	void  async_alarm_arm_away();
	void alarm_arm_night();
	void  async_alarm_arm_night();
	void alarm_trigger();
	void  async_alarm_trigger();
	void alarm_arm_custom_bypass();
	void  async_alarm_arm_custom_bypass();
	void supported_features();
	void state_attributes();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif