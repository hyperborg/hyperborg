/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef IFTTT_H
#define IFTTT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class ifttt : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ifttt.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ifttt();
    ~ifttt();

    QString name() 		{ return "ifttt"; }
    QString description()	{ return "Support to trigger Maker IFTTT recipes."; }

protected:
    	void async_setup();
	void trigger_service();
	void handle_webhook();
	void async_setup_entry();
	void async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif