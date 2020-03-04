/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef EMONCMS_HISTORY_H
#define EMONCMS_HISTORY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class emoncms_history : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "emoncms_history.json");
    Q_INTERFACES(HyPluginInterface);
public:
    emoncms_history();
    ~emoncms_history();

    QString name() 		{ return "emoncms_history"; }
    QString description()	{ return "Support for sending data to Emoncms."; }

protected:
    	void setup();
	void send_data();
	void update_emoncms();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif