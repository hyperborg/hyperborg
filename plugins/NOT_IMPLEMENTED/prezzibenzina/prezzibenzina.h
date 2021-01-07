/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PREZZIBENZINA_H
#define PREZZIBENZINA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class prezzibenzina : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "prezzibenzina.json");
    Q_INTERFACES(HyPluginInterface);
public:
    prezzibenzina(QObject *parent=nullptr);
    ~prezzibenzina();

    QString name() 		{ return "prezzibenzina"; }
    QString description()	{ return "The prezzibenzina component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif