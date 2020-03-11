/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef STIEBEL_ELTRON_H
#define STIEBEL_ELTRON_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class stiebel_eltron : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "stiebel_eltron.json");
    Q_INTERFACES(HyPluginInterface);
public:
    stiebel_eltron(QObject *parent=nullptr);
    ~stiebel_eltron();

    QString name() 		{ return "stiebel_eltron"; }
    QString description()	{ return "The component for STIEBEL ELTRON heat pumps with ISGWeb Modbus module."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void __init__();
	void update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif