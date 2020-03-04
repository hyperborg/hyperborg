/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef FOURSQUARE_H
#define FOURSQUARE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class foursquare : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "foursquare.json");
    Q_INTERFACES(HyPluginInterface);
public:
    foursquare();
    ~foursquare();

    QString name() 		{ return "foursquare"; }
    QString description()	{ return "Support for the Foursquare (Swarm) API."; }

protected:
    	void setup();
	void checkin_user();
	void __init__();
	void  post();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif