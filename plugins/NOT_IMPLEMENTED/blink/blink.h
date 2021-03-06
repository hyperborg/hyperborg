/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef BLINK_H
#define BLINK_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class blink : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "blink.json");
    Q_INTERFACES(HyPluginInterface);
public:
    blink(QObject *parent=nullptr);
    ~blink();

    QString name() 		{ return "blink"; }
    QString description()	{ return "Support for Blink Home Camera System."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void trigger_camera();
	void blink_refresh();
	void async_save_video();
	void async_handle_save_video_service();
	void _write_video();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif