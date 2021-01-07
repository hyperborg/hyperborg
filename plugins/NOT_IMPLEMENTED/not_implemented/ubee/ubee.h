/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef UBEE_H
#define UBEE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class ubee : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ubee.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ubee(QObject *parent=nullptr);
    ~ubee();

    QString name() 		{ return "ubee"; }
    QString description()	{ return "The ubee component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif