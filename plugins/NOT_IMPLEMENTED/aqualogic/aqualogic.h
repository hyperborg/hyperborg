/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef AQUALOGIC_H
#define AQUALOGIC_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class aqualogic : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "aqualogic.json");
    Q_INTERFACES(HyPluginInterface);
public:
    aqualogic(QObject *parent=nullptr);
    ~aqualogic();

    QString name() 		{ return "aqualogic"; }
    QString description()	{ return "Support for AquaLogic devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void __init__();
	void start_listen();
	void shutdown();
	void data_changed();
	void run();
	void panel();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif