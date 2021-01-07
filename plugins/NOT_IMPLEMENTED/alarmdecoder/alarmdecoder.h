/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ALARMDECODER_H
#define ALARMDECODER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class alarmdecoder : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "alarmdecoder.json");
    Q_INTERFACES(HyPluginInterface);
public:
    alarmdecoder(QObject *parent=nullptr);
    ~alarmdecoder();

    QString name() 		{ return "alarmdecoder"; }
    QString description()	{ return "Support for AlarmDecoder devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void stop_alarmdecoder();
	void open_connection();
	void handle_closed_connection();
	void handle_message();
	void handle_rfx_message();
	void zone_fault_callback();
	void zone_restore_callback();
	void handle_rel_message();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif