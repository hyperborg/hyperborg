/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MAGICSEAWEED_H
#define MAGICSEAWEED_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class magicseaweed : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "magicseaweed.json");
    Q_INTERFACES(HyPluginInterface);
public:
    magicseaweed(QObject *parent=nullptr);
    ~magicseaweed();

    QString name() 		{ return "magicseaweed"; }
    QString description()	{ return "The magicseaweed component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif