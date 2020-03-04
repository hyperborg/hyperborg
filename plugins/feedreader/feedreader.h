/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef FEEDREADER_H
#define FEEDREADER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class feedreader : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "feedreader.json");
    Q_INTERFACES(HyPluginInterface);
public:
    feedreader();
    ~feedreader();

    QString name() 		{ return "feedreader"; }
    QString description()	{ return "Support for RSS/Atom feeds."; }

protected:
    	void setup();
	void __init__();
	void _log_no_entries();
	void _init_regular_updates();
	void last_update_successful();
	void _update();
	void _filter_entries();
	void _update_and_fire_entry();
	void _publish_new_entries();
	void _fetch_data();
	void get_timestamp();
	void put_timestamp();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif