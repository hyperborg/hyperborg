/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NESS_ALARM_H
#define NESS_ALARM_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class ness_alarm : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ness_alarm.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ness_alarm();
    ~ness_alarm();

    QString name() 		{ return "ness_alarm"; }
    QString description()	{ return "Support for Ness D8X/D16X devices."; }

protected:
    	void  async_setup();
	void  _close();
	void on_zone_change();
	void on_state_change();
	void  handle_panic();
	void  handle_aux();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif