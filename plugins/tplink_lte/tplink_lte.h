/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TPLINK_LTE_H
#define TPLINK_LTE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class tplink_lte : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "tplink_lte.json");
    Q_INTERFACES(HyPluginInterface);
public:
    tplink_lte();
    ~tplink_lte();

    QString name() 		{ return "tplink_lte"; }
    QString description()	{ return "Support for TP-Link LTE modems."; }

protected:
    	void get_modem_data();
	void async_setup();
	void _setup_lte();
	void cleanup_retry();
	void _login();
	void cleanup();
	void _retry_login();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif