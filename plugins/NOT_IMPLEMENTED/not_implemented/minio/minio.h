/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MINIO_H
#define MINIO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class minio : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "minio.json");
    Q_INTERFACES(HyPluginInterface);
public:
    minio(QObject *parent=nullptr);
    ~minio();

    QString name() 		{ return "minio"; }
    QString description()	{ return "Minio component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void _setup_listener();
	void _render_service_value();
	void put_file();
	void get_file();
	void remove_file();
	void get_minio_endpoint();
	void __init__();
	void run();
	void queue();
	void stop();
	void start_handler();
	void stop_handler();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif