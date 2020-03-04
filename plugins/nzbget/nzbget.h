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

class nzbget : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "nzbget.json");
    Q_INTERFACES(HyPluginInterface);
public:
    nzbget();
    ~nzbget();

    QString name() 		{ return "nzbget"; }
    QString description()	{ return "The nzbget component."; }

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