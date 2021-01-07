/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NZBGET_H
#define NZBGET_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class nzbget : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "nzbget.json");
    Q_INTERFACES(HyPluginInterface);
public:
    nzbget(QObject *parent=nullptr);
    ~nzbget();

    QString name() 		{ return "nzbget"; }
    QString description()	{ return "The nzbget component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void service_handler();
	void refresh();
	void __init__();
	void update();
	void init_download_list();
	void check_completed_downloads();
	void pause_download();
	void resume_download();
	void rate();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif