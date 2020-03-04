/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ELKM1_H
#define ELKM1_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class elkm1 : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "elkm1.json");
    Q_INTERFACES(HyPluginInterface);
public:
    elkm1();
    ~elkm1();

    QString name() 		{ return "elkm1"; }
    QString description()	{ return "Support the ElkM1 Gold and ElkM1 EZ8 alarm/integration panels."; }

protected:
    	void _host_validator();
	void _elk_range_validator();
	void _housecode_to_int();
	void _elk_value();
	void _has_all_unique_prefixes();
	void  async_setup();
	void _included();
	void _create_elk_services();
	void _speak_word_service();
	void _speak_phrase_service();
	void create_elk_entities();
	void __init__();
	void unique_id();
	void should_poll();
	void device_state_attributes();
	void available();
	void initial_attrs();
	void _element_changed();
	void _element_callback();
	void  async_added_to_hass();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif