/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LOCATIVE_H
#define LOCATIVE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class locative : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "locative.json");
    Q_INTERFACES(HyPluginInterface);
public:
    locative();
    ~locative();

    QString name() 		{ return "locative"; }
    QString description()	{ return "Support for Locative."; }

protected:
    	void _id();
	void _validate_test_mode();
	void  async_setup();
	void  handle_webhook();
	void  async_setup_entry();
	void  async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif