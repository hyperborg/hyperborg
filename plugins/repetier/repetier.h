/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef REPETIER_H
#define REPETIER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class repetier : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "repetier.json");
    Q_INTERFACES(HyPluginInterface);
public:
    repetier();
    ~repetier();

    QString name() 		{ return "repetier"; }
    QString description()	{ return "Support for Repetier-Server sensors."; }

protected:
    	void has_all_unique_names();
	void setup();
	void __init__();
	void get_data();
	void update();
	void _load_entities();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif