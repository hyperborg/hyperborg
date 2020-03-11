/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DEUTSCHE_BAHN_H
#define DEUTSCHE_BAHN_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class deutsche_bahn : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "deutsche_bahn.json");
    Q_INTERFACES(HyPluginInterface);
public:
    deutsche_bahn(QObject *parent=nullptr);
    ~deutsche_bahn();

    QString name() 		{ return "deutsche_bahn"; }
    QString description()	{ return "The deutsche_bahn component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif