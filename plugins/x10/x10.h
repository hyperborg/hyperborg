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

class x10 : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "x10.json");
    Q_INTERFACES(HyPluginInterface);
public:
    x10();
    ~x10();

    QString name() 		{ return "x10"; }
    QString description()	{ return "The x10 component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif