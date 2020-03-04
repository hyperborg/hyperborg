/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef CALENDAR_H
#define CALENDAR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class calendar : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "calendar.json");
    Q_INTERFACES(HyPluginInterface);
public:
    calendar();
    ~calendar();

    QString name() 		{ return "calendar"; }
    QString description()	{ return "Support for Google Calendar event device sensors."; }

protected:
    	void  async_setup();
	void get_date();
	void normalize_event();
	void calculate_offset();
	void is_offset_reached();
	void event();
	void state_attributes();
	void state();
	void  async_get_events();
	void __init__();
	void  get();
	void __init__();
	void  get();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif