/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GOGOGATE2_H
#define GOGOGATE2_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class gogogate2 : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "gogogate2.json");
    Q_INTERFACES(HyPluginInterface);
public:
    gogogate2();
    ~gogogate2();

    QString name() 		{ return "gogogate2"; }
    QString description()	{ return "The gogogate2 component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif