/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MODBUS_H
#define MODBUS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class modbus : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "modbus.json");
    Q_INTERFACES(HyPluginInterface);
public:
    modbus(QObject *parent=nullptr);
    ~modbus();

    QString name() 		{ return "modbus"; }
    QString description()	{ return "Support for Modbus."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup_client();
	void setup();
	void stop_modbus();
	void start_modbus();
	void write_register();
	void write_coil();
	void __init__();
	void close();
	void connect();
	void read_coils();
	void read_discrete_inputs();
	void read_input_registers();
	void read_holding_registers();
	void write_registers();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif