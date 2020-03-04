/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef OSRAMLIGHTIFY_H
#define OSRAMLIGHTIFY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class osramlightify : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "osramlightify.json");
    Q_INTERFACES(HyPluginInterface);
public:
    osramlightify();
    ~osramlightify();

    QString name() 		{ return "osramlightify"; }
    QString description()	{ return "The osramlightify component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif