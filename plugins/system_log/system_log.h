/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SYSTEM_LOG_H
#define SYSTEM_LOG_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class system_log : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "system_log.json");
    Q_INTERFACES(HyPluginInterface);
public:
    system_log();
    ~system_log();

    QString name() 		{ return "system_log"; }
    QString description()	{ return "Support for system log."; }

protected:
    	void _figure_out_source();
	void __init__();
	void to_dict();
	void __init__();
	void add_entry();
	void to_list();
	void __init__();
	void emit();
	void  async_setup();
	void  async_service_handler();
	void  async_shutdown_handler();
	void __init__();
	void  get();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif