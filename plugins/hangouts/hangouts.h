/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HANGOUTS_H
#define HANGOUTS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class hangouts : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "hangouts.json");
    Q_INTERFACES(HyPluginInterface);
public:
    hangouts();
    ~hangouts();

    QString name() 		{ return "hangouts"; }
    QString description()	{ return "Support for Hangouts."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif