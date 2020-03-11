/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef OCTOPRINT_H
#define OCTOPRINT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class octoprint : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "octoprint.json");
    Q_INTERFACES(HyPluginInterface);
public:
    octoprint(QObject *parent=nullptr);
    ~octoprint();

    QString name() 		{ return "octoprint"; }
    QString description()	{ return "Support for monitoring OctoPrint 3D printers."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void has_all_unique_names();
	void ensure_valid_path();
	void setup();
	void device_discovered();
	void __init__();
	void get_tools();
	void update();
	void get_value_from_json();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif