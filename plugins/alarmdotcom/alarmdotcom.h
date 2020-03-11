/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ALARMDOTCOM_H
#define ALARMDOTCOM_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class alarmdotcom : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "alarmdotcom.json");
    Q_INTERFACES(HyPluginInterface);
public:
    alarmdotcom(QObject *parent=nullptr);
    ~alarmdotcom();

    QString name() 		{ return "alarmdotcom"; }
    QString description()	{ return "The alarmdotcom component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif