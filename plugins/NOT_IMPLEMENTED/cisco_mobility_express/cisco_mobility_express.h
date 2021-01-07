/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef CISCO_MOBILITY_EXPRESS_H
#define CISCO_MOBILITY_EXPRESS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class cisco_mobility_express : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "cisco_mobility_express.json");
    Q_INTERFACES(HyPluginInterface);
public:
    cisco_mobility_express(QObject *parent=nullptr);
    ~cisco_mobility_express();

    QString name() 		{ return "cisco_mobility_express"; }
    QString description()	{ return "Component to embed Cisco Mobility Express."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif