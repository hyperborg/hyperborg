/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef INTENT_H
#define INTENT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class intent : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "intent.json");
    Q_INTERFACES(HyPluginInterface);
public:
    intent();
    ~intent();

    QString name() 		{ return "intent"; }
    QString description()	{ return "The Intent integration."; }

protected:
    	void async_setup();
	void _async_process_intent();
	void post();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif