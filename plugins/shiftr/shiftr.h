/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SHIFTR_H
#define SHIFTR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class shiftr : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "shiftr.json");
    Q_INTERFACES(HyPluginInterface);
public:
    shiftr();
    ~shiftr();

    QString name() 		{ return "shiftr"; }
    QString description()	{ return "Support for Shiftr.io."; }

protected:
    	void setup();
	void stop_shiftr();
	void shiftr_event_listener();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif