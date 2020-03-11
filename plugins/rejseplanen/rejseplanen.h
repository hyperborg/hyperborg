/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef REJSEPLANEN_H
#define REJSEPLANEN_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class rejseplanen : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "rejseplanen.json");
    Q_INTERFACES(HyPluginInterface);
public:
    rejseplanen(QObject *parent=nullptr);
    ~rejseplanen();

    QString name() 		{ return "rejseplanen"; }
    QString description()	{ return "The rejseplanen component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif