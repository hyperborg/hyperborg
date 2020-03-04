/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PS4_H
#define PS4_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class ps4 : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ps4.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ps4();
    ~ps4();

    QString name() 		{ return "ps4"; }
    QString description()	{ return "Support for PlayStation 4 consoles."; }

protected:
    	void __init__();
	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void async_migrate_entry();
	void format_unique_id();
	void load_games();
	void save_games();
	void _reformat_data();
	void service_handle();
	void async_service_command();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif