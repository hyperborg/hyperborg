/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GOOGLE_H
#define GOOGLE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class google : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "google.json");
    Q_INTERFACES(HyPluginInterface);
public:
    google();
    ~google();

    QString name() 		{ return "google"; }
    QString description()	{ return "Support for Google - Calendar Event Devices."; }

protected:
    	void do_authentication();
	void step2_exchange();
	void setup();
	void check_correct_scopes();
	void setup_services();
	void _found_calendar();
	void _scan_for_calendars();
	void _add_event();
	void do_setup();
	void __init__();
	void get();
	void get_calendar_info();
	void load_config();
	void update_config();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif