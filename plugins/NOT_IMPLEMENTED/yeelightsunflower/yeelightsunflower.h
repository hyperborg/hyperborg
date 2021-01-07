/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef YEELIGHTSUNFLOWER_H
#define YEELIGHTSUNFLOWER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class yeelightsunflower : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "yeelightsunflower.json");
    Q_INTERFACES(HyPluginInterface);
public:
    yeelightsunflower(QObject *parent=nullptr);
    ~yeelightsunflower();

    QString name() 		{ return "yeelightsunflower"; }
    QString description()	{ return "The yeelightsunflower component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif