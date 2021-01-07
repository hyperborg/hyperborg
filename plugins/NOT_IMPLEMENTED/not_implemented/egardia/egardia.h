/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef EGARDIA_H
#define EGARDIA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class egardia : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "egardia.json");
    Q_INTERFACES(HyPluginInterface);
public:
    egardia(QObject *parent=nullptr);
    ~egardia();

    QString name() 		{ return "egardia"; }
    QString description()	{ return "Interfaces with Egardia/Woonveilig alarm control panel."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void handle_stop_event();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif