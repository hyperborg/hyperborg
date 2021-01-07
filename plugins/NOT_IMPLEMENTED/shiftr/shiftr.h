/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SHIFTR_H
#define SHIFTR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class shiftr : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "shiftr.json");
    Q_INTERFACES(HyPluginInterface);
public:
    shiftr(QObject *parent=nullptr);
    ~shiftr();

    QString name() 		{ return "shiftr"; }
    QString description()	{ return "Support for Shiftr.io."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void stop_shiftr();
	void shiftr_event_listener();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif