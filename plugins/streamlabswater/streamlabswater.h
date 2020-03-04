/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef STREAMLABSWATER_H
#define STREAMLABSWATER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class streamlabswater : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "streamlabswater.json");
    Q_INTERFACES(HyPluginInterface);
public:
    streamlabswater();
    ~streamlabswater();

    QString name() 		{ return "streamlabswater"; }
    QString description()	{ return "Support for Streamlabs Water Monitor devices."; }

protected:
    	void setup();
	void set_away_mode();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif