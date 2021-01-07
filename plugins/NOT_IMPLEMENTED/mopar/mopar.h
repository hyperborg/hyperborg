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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class mopar : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mopar.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mopar(QObject *parent=nullptr);
    ~mopar();

    QString name() 		{ return "mopar"; }
    QString description()	{ return "Support for Mopar vehicles."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

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