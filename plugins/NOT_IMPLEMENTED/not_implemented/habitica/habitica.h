/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HABITICA_H
#define HABITICA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class habitica : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "habitica.json");
    Q_INTERFACES(HyPluginInterface);
public:
    habitica(QObject *parent=nullptr);
    ~habitica();

    QString name() 		{ return "habitica"; }
    QString description()	{ return "Support for Habitica devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void has_all_unique_users();
	void has_all_unique_users_names();
	void async_setup();
	void __call__();
	void handle_api_call();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif