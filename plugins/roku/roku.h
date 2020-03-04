/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ROKU_H
#define ROKU_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class roku : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "roku.json");
    Q_INTERFACES(HyPluginInterface);
public:
    roku();
    ~roku();

    QString name() 		{ return "roku"; }
    QString description()	{ return "Support for Roku."; }

protected:
    	void setup();
	void service_handler();
	void roku_discovered();
	void scan_for_rokus();
	void _setup_roku();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif