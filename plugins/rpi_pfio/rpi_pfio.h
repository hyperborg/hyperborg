/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RPI_PFIO_H
#define RPI_PFIO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class rpi_pfio : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "rpi_pfio.json");
    Q_INTERFACES(HyPluginInterface);
public:
    rpi_pfio(QObject *parent=nullptr);
    ~rpi_pfio();

    QString name() 		{ return "rpi_pfio"; }
    QString description()	{ return "Support for controlling the PiFace Digital I/O module on a RPi."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void cleanup_pfio();
	void prepare_pfio();
	void write_output();
	void read_input();
	void edge_detect();
	void activate_listener();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif