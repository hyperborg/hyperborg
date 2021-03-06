/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef JUICENET_H
#define JUICENET_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class juicenet : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "juicenet.json");
    Q_INTERFACES(HyPluginInterface);
public:
    juicenet(QObject *parent=nullptr);
    ~juicenet();

    QString name() 		{ return "juicenet"; }
    QString description()	{ return "Support for Juicenet cloud."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void __init__();
	void update();
	void _manufacturer_device_id();
	void _token();
	void unique_id();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif