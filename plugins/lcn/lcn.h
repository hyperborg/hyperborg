/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LCN_H
#define LCN_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class lcn : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "lcn.json");
    Q_INTERFACES(HyPluginInterface);
public:
    lcn();
    ~lcn();

    QString name() 		{ return "lcn"; }
    QString description()	{ return "Support for LCN devices."; }

protected:
    	void  async_setup();
	void __init__();
	void should_poll();
	void  async_added_to_hass();
	void name();
	void input_received();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif