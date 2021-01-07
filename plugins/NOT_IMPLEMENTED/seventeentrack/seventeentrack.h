/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SEVENTEENTRACK_H
#define SEVENTEENTRACK_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class seventeentrack : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "seventeentrack.json");
    Q_INTERFACES(HyPluginInterface);
public:
    seventeentrack(QObject *parent=nullptr);
    ~seventeentrack();

    QString name() 		{ return "seventeentrack"; }
    QString description()	{ return "The seventeentrack component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif