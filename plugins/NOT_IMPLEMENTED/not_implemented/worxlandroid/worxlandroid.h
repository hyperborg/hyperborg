/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef WORXLANDROID_H
#define WORXLANDROID_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class worxlandroid : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "worxlandroid.json");
    Q_INTERFACES(HyPluginInterface);
public:
    worxlandroid(QObject *parent=nullptr);
    ~worxlandroid();

    QString name() 		{ return "worxlandroid"; }
    QString description()	{ return "The worxlandroid component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif