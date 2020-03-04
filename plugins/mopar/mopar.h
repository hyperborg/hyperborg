/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MOPAR_H
#define MOPAR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class mopar : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mopar.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mopar();
    ~mopar();

    QString name() 		{ return "mopar"; }
    QString description()	{ return "Support for Mopar vehicles."; }

protected:
    	void setup();
	void handle_horn();
	void __init__();
	void update();
	void attribution();
	void get_vehicle_name();
	void actuate();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif