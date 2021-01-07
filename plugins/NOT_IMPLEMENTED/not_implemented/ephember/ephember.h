/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef EPHEMBER_H
#define EPHEMBER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class ephember : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ephember.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ephember(QObject *parent=nullptr);
    ~ephember();

    QString name() 		{ return "ephember"; }
    QString description()	{ return "The ephember component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif