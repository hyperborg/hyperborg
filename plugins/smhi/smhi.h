/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SMHI_H
#define SMHI_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class smhi : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "smhi.json");
    Q_INTERFACES(HyPluginInterface);
public:
    smhi();
    ~smhi();

    QString name() 		{ return "smhi"; }
    QString description()	{ return "Support for the Swedish weather institute weather service."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif