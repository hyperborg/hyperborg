/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DIALOGFLOW_H
#define DIALOGFLOW_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class dialogflow : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "dialogflow.json");
    Q_INTERFACES(HyPluginInterface);
public:
    dialogflow();
    ~dialogflow();

    QString name() 		{ return "dialogflow"; }
    QString description()	{ return "Support for Dialogflow webhook."; }

protected:
    	void  async_setup();
	void  handle_webhook();
	void  async_setup_entry();
	void  async_unload_entry();
	void dialogflow_error_response();
	void get_api_version();
	void  async_handle_message();
	void __init__();
	void add_speech();
	void as_dict();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif