/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef VASTTRAFIK_H
#define VASTTRAFIK_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class vasttrafik : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "vasttrafik.json");
    Q_INTERFACES(HyPluginInterface);
public:
    vasttrafik();
    ~vasttrafik();

    QString name() 		{ return "vasttrafik"; }
    QString description()	{ return "The vasttrafik component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif