/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SNIPS_H
#define SNIPS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class snips : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "snips.json");
    Q_INTERFACES(HyPluginInterface);
public:
    snips(QObject *parent=nullptr);
    ~snips();

    QString name() 		{ return "snips"; }
    QString description()	{ return "Support for Snips on-device ASR and NLU."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void async_set_feedback();
	void message_received();
	void snips_say();
	void snips_say_action();
	void feedback_on();
	void feedback_off();
	void resolve_slot_values();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif