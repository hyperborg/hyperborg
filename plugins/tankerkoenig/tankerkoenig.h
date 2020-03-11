/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TANKERKOENIG_H
#define TANKERKOENIG_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class tankerkoenig : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "tankerkoenig.json");
    Q_INTERFACES(HyPluginInterface);
public:
    tankerkoenig(QObject *parent=nullptr);
    ~tankerkoenig();

    QString name() 		{ return "tankerkoenig"; }
    QString description()	{ return "Ask tankerkoenig.de for petrol price information."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void __init__();
	void setup();
	void fetch_data();
	void add_station();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif