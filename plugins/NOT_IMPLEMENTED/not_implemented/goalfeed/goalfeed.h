/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GOALFEED_H
#define GOALFEED_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class goalfeed : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "goalfeed.json");
    Q_INTERFACES(HyPluginInterface);
public:
    goalfeed(QObject *parent=nullptr);
    ~goalfeed();

    QString name() 		{ return "goalfeed"; }
    QString description()	{ return "Component for the Goalfeed service."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void goal_handler();
	void connect_handler();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif