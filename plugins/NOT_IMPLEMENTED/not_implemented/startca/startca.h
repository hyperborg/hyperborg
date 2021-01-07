/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef STARTCA_H
#define STARTCA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class startca : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "startca.json");
    Q_INTERFACES(HyPluginInterface);
public:
    startca(QObject *parent=nullptr);
    ~startca();

    QString name() 		{ return "startca"; }
    QString description()	{ return "The startca component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif