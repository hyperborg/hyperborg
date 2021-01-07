/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef EQ3BTSMART_H
#define EQ3BTSMART_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class eq3btsmart : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "eq3btsmart.json");
    Q_INTERFACES(HyPluginInterface);
public:
    eq3btsmart(QObject *parent=nullptr);
    ~eq3btsmart();

    QString name() 		{ return "eq3btsmart"; }
    QString description()	{ return "The eq3btsmart component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif