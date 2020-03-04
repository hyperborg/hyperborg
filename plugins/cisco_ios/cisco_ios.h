/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef CISCO_IOS_H
#define CISCO_IOS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class cisco_ios : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "cisco_ios.json");
    Q_INTERFACES(HyPluginInterface);
public:
    cisco_ios();
    ~cisco_ios();

    QString name() 		{ return "cisco_ios"; }
    QString description()	{ return "The cisco_ios component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif