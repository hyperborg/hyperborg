/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GOOGLE_ASSISTANT_H
#define GOOGLE_ASSISTANT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class google_assistant : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "google_assistant.json");
    Q_INTERFACES(HyPluginInterface);
public:
    google_assistant();
    ~google_assistant();

    QString name() 		{ return "google_assistant"; }
    QString description()	{ return "Support for Actions on Google Assistant Smart Home Control."; }

protected:
    	void _check_report_state();
	void  async_setup();
	void  request_sync_service_handler();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif