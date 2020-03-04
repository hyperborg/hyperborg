/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef EMULATED_ROKU_H
#define EMULATED_ROKU_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class emulated_roku : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "emulated_roku.json");
    Q_INTERFACES(HyPluginInterface);
public:
    emulated_roku();
    ~emulated_roku();

    QString name() 		{ return "emulated_roku"; }
    QString description()	{ return "Support for Roku API emulation."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif