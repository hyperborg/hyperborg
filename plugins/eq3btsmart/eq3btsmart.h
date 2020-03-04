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

class eq3btsmart : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "eq3btsmart.json");
    Q_INTERFACES(HyPluginInterface);
public:
    eq3btsmart();
    ~eq3btsmart();

    QString name() 		{ return "eq3btsmart"; }
    QString description()	{ return "The eq3btsmart component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif