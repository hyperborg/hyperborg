/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef INCOMFORT_H
#define INCOMFORT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class incomfort : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "incomfort.json");
    Q_INTERFACES(HyPluginInterface);
public:
    incomfort();
    ~incomfort();

    QString name() 		{ return "incomfort"; }
    QString description()	{ return "Support for an Intergas boiler via an InComfort/Intouch Lan2RF gateway."; }

protected:
    	void  async_setup();
	void __init__();
	void unique_id();
	void name();
	void  async_added_to_hass();
	void _refresh();
	void should_poll();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif