/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LIGHT_H
#define LIGHT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class light : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "light.json");
    Q_INTERFACES(HyPluginInterface);
public:
    light();
    ~light();

    QString name() 		{ return "light"; }
    QString description()	{ return "Provides functionality to interact with lights."; }

protected:
    	void is_on();
	void preprocess_turn_on_alternatives();
	void preprocess_turn_off();
	void  async_setup();
	void preprocess_data();
	void  async_handle_light_on_service();
	void  async_setup_entry();
	void  async_unload_entry();
	void  load_profiles();
	void load_profile_data();
	void get();
	void get_default();
	void brightness();
	void hs_color();
	void color_temp();
	void min_mireds();
	void max_mireds();
	void white_value();
	void effect_list();
	void effect();
	void capability_attributes();
	void state_attributes();
	void supported_features();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif