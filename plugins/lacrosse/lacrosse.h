/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LACROSSE_H
#define LACROSSE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class lacrosse : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "lacrosse.json");
    Q_INTERFACES(HyPluginInterface);
public:
    lacrosse();
    ~lacrosse();

    QString name() 		{ return "lacrosse"; }
    QString description()	{ return "The lacrosse component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif