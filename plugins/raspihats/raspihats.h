/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RASPIHATS_H
#define RASPIHATS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class raspihats : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "raspihats.json");
    Q_INTERFACES(HyPluginInterface);
public:
    raspihats();
    ~raspihats();

    QString name() 		{ return "raspihats"; }
    QString description()	{ return "Support for controlling raspihats boards."; }

protected:
    	void setup();
	void start_i2c_hats_keep_alive();
	void stop_i2c_hats_keep_alive();
	void log_message();
	void setup();
	void register_callback();
	void scan();
	void __init__();
	void register_board();
	void run();
	void _read_status();
	void start_keep_alive();
	void stop_keep_alive();
	void register_di_callback();
	void register_online_callback();
	void read_di();
	void write_dq();
	void read_dq();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif