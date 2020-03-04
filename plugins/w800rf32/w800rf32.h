/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef W800RF32_H
#define W800RF32_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class w800rf32 : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "w800rf32.json");
    Q_INTERFACES(HyPluginInterface);
public:
    w800rf32();
    ~w800rf32();

    QString name() 		{ return "w800rf32"; }
    QString description()	{ return "Support for w800rf32 devices."; }

protected:
    	void setup();
	void handle_receive();
	void _start_w800rf32();
	void _shutdown_w800rf32();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif