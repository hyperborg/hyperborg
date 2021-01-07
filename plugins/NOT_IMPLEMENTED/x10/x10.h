/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef X10_H
#define X10_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class x10 : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "x10.json");
    Q_INTERFACES(HyPluginInterface);
public:
    x10(QObject *parent=nullptr);
    ~x10();

    QString name() 		{ return "x10"; }
    QString description()	{ return "The x10 component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif