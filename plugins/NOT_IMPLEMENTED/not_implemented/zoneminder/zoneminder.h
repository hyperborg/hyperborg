/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ZONEMINDER_H
#define ZONEMINDER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class zoneminder : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "zoneminder.json");
    Q_INTERFACES(HyPluginInterface);
public:
    zoneminder(QObject *parent=nullptr);
    ~zoneminder();

    QString name() 		{ return "zoneminder"; }
    QString description()	{ return "Support for ZoneMinder."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void set_active_state();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif