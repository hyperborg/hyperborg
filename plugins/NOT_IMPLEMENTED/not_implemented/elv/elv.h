/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ELV_H
#define ELV_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class elv : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "elv.json");
    Q_INTERFACES(HyPluginInterface);
public:
    elv(QObject *parent=nullptr);
    ~elv();

    QString name() 		{ return "elv"; }
    QString description()	{ return "The Elv integration."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif