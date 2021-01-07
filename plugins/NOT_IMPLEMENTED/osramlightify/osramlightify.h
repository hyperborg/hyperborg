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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class osramlightify : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "osramlightify.json");
    Q_INTERFACES(HyPluginInterface);
public:
    osramlightify(QObject *parent=nullptr);
    ~osramlightify();

    QString name() 		{ return "osramlightify"; }
    QString description()	{ return "The osramlightify component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif