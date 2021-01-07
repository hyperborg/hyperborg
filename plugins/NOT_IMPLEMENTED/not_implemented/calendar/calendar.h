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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class calendar : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "calendar.json");
    Q_INTERFACES(HyPluginInterface);
public:
    calendar(QObject *parent=nullptr);
    ~calendar();

    QString name() 		{ return "calendar"; }
    QString description()	{ return "Support for Google Calendar event device sensors."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void get_date();
	void normalize_event();
	void calculate_offset();
	void is_offset_reached();
	void event();
	void state_attributes();
	void state();
	void async_get_events();
	void __init__();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif