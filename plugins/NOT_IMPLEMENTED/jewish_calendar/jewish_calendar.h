/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef JEWISH_CALENDAR_H
#define JEWISH_CALENDAR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class jewish_calendar : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "jewish_calendar.json");
    Q_INTERFACES(HyPluginInterface);
public:
    jewish_calendar(QObject *parent=nullptr);
    ~jewish_calendar();

    QString name() 		{ return "jewish_calendar"; }
    QString description()	{ return "The jewish_calendar component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif