/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LOCK_H
#define LOCK_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class lock : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "lock.json");
    Q_INTERFACES(HyPluginInterface);
public:
    lock();
    ~lock();

    QString name() 		{ return "lock"; }
    QString description()	{ return "Component to interface with locks that can be controlled remotely."; }

protected:
    	void is_locked();
	void  async_setup();
	void  async_setup_entry();
	void  async_unload_entry();
	void changed_by();
	void code_format();
	void is_locked();
	void lock();
	void  async_lock();
	void unlock();
	void  async_unlock();
	void open();
	void  async_open();
	void state_attributes();
	void state();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif