/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TOTALCONNECT_H
#define TOTALCONNECT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class totalconnect : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "totalconnect.json");
    Q_INTERFACES(HyPluginInterface);
public:
    totalconnect(QObject *parent=nullptr);
    ~totalconnect();

    QString name() 		{ return "totalconnect"; }
    QString description()	{ return "The totalconnect component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void __init__();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif