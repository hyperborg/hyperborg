/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef IZONE_H
#define IZONE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class izone : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "izone.json");
    Q_INTERFACES(HyPluginInterface);
public:
    izone();
    ~izone();

    QString name() 		{ return "izone"; }
    QString description()	{ return "Platform for the iZone AC."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif