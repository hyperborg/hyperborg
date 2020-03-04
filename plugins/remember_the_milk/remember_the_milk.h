/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef REMEMBER_THE_MILK_H
#define REMEMBER_THE_MILK_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class remember_the_milk : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "remember_the_milk.json");
    Q_INTERFACES(HyPluginInterface);
public:
    remember_the_milk();
    ~remember_the_milk();

    QString name() 		{ return "remember_the_milk"; }
    QString description()	{ return "Support to interact with Remember The Milk."; }

protected:
    	void setup();
	void _create_instance();
	void _register_new_account();
	void register_account_callback();
	void __init__();
	void save_config();
	void get_token();
	void set_token();
	void delete_token();
	void _initialize_profile();
	void get_rtm_id();
	void set_rtm_id();
	void delete_rtm_id();
	void __init__();
	void _check_token();
	void create_task();
	void complete_task();
	void name();
	void state();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif