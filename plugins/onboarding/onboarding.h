/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ONBOARDING_H
#define ONBOARDING_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class onboarding : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "onboarding.json");
    Q_INTERFACES(HyPluginInterface);
public:
    onboarding();
    ~onboarding();

    QString name() 		{ return "onboarding"; }
    QString description()	{ return "Support to help onboard new users."; }

protected:
    	void _async_migrate_func();
	void async_is_onboarded();
	void async_is_user_onboarded();
	void async_setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif