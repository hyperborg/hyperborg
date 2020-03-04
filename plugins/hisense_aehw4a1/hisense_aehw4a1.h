/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HISENSE_AEHW4A1_H
#define HISENSE_AEHW4A1_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class hisense_aehw4a1 : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "hisense_aehw4a1.json");
    Q_INTERFACES(HyPluginInterface);
public:
    hisense_aehw4a1();
    ~hisense_aehw4a1();

    QString name() 		{ return "hisense_aehw4a1"; }
    QString description()	{ return "The Hisense AEH-W4A1 integration."; }

protected:
    	void coerce_ip();
	void  async_setup();
	void  async_setup_entry();
	void  async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif