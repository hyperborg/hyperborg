/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GPMDP_H
#define GPMDP_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class gpmdp : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "gpmdp.json");
    Q_INTERFACES(HyPluginInterface);
public:
    gpmdp();
    ~gpmdp();

    QString name() 		{ return "gpmdp"; }
    QString description()	{ return "The gpmdp component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif