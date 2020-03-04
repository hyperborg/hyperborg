/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SPC_H
#define SPC_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class spc : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "spc.json");
    Q_INTERFACES(HyPluginInterface);
public:
    spc();
    ~spc();

    QString name() 		{ return "spc"; }
    QString description()	{ return "Support for Vanderbilt (formerly Siemens) SPC alarm systems."; }

protected:
    	void  async_setup();
	void  async_upate_callback();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif