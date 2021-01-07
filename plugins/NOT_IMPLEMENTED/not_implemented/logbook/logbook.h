/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LOGBOOK_H
#define LOGBOOK_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class logbook : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "logbook.json");
    Q_INTERFACES(HyPluginInterface);
public:
    logbook(QObject *parent=nullptr);
    ~logbook();

    QString name() 		{ return "logbook"; }
    QString description()	{ return "Event parser and human readable log generator."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void log_entry();
	void async_log_entry();
	void async_setup();
	void log_message();
	void __init__();
	void json_events();
	void humanify();
	void _get_related_entity_ids();
	void _generate_filter_from_config();
	void _get_events();
	void yield_events();
	void _keep_event();
	void _entry_message_from_state();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif