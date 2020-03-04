/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef INTENT_SCRIPT_H
#define INTENT_SCRIPT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class intent_script : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "intent_script.json");
    Q_INTERFACES(HyPluginInterface);
public:
    intent_script();
    ~intent_script();

    QString name() 		{ return "intent_script"; }
    QString description()	{ return "Handle intents with scripts."; }

protected:
    	void async_setup();
	void __init__();
	void async_handle();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif