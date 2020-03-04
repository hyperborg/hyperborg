/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PYTHON_SCRIPT_H
#define PYTHON_SCRIPT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class python_script : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "python_script.json");
    Q_INTERFACES(HyPluginInterface);
public:
    python_script();
    ~python_script();

    QString name() 		{ return "python_script"; }
    QString description()	{ return "Component to allow running Python scripts."; }

protected:
    	void setup();
	void reload_scripts_handler();
	void discover_scripts();
	void python_script_service_handler();
	void execute_script();
	void execute();
	void protected_getattr();
	void __init__();
	void _call_print();
	void sleep();
	void __getattr__();
	void wrapper();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif