/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HISTORY_H
#define HISTORY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class history : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "history.json");
    Q_INTERFACES(HyPluginInterface);
public:
    history();
    ~history();

    QString name() 		{ return "history"; }
    QString description()	{ return "Provide pre-made queries on top of the recorder component."; }

protected:
    	void get_significant_states();
	void state_changes_during_period();
	void get_last_state_changes();
	void get_states();
	void states_to_json();
	void get_state();
	void  async_setup();
	void __init__();
	void  get();
	void __init__();
	void apply();
	void _is_significant();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif