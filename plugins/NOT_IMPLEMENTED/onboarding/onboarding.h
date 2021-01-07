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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class onboarding : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "onboarding.json");
    Q_INTERFACES(HyPluginInterface);
public:
    onboarding(QObject *parent=nullptr);
    ~onboarding();

    QString name() 		{ return "onboarding"; }
    QString description()	{ return "Support to help onboard new users."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

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