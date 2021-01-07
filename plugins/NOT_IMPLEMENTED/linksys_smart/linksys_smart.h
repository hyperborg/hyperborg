/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LINKSYS_SMART_H
#define LINKSYS_SMART_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class linksys_smart : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "linksys_smart.json");
    Q_INTERFACES(HyPluginInterface);
public:
    linksys_smart(QObject *parent=nullptr);
    ~linksys_smart();

    QString name() 		{ return "linksys_smart"; }
    QString description()	{ return "The linksys_smart component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif