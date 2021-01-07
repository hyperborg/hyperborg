/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef CONVERSATION_H
#define CONVERSATION_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class conversation : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "conversation.json");
    Q_INTERFACES(HyPluginInterface);
public:
    conversation(QObject *parent=nullptr);
    ~conversation();

    QString name() 		{ return "conversation"; }
    QString description()	{ return "Support for functionality to have conversations with Home Assistant."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_set_agent();
	void async_setup();
	void handle_service();
	void websocket_process();
	void websocket_get_agent_info();
	void websocket_set_onboarding();
	void post();
	void _get_agent();
	void _async_converse();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif