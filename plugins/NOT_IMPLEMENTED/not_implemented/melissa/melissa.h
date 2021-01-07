/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MELISSA_H
#define MELISSA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class melissa : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "melissa.json");
    Q_INTERFACES(HyPluginInterface);
public:
    melissa(QObject *parent=nullptr);
    ~melissa();

    QString name() 		{ return "melissa"; }
    QString description()	{ return "Support for Melissa climate."; }
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