/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef CLICKATELL_H
#define CLICKATELL_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class clickatell : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "clickatell.json");
    Q_INTERFACES(HyPluginInterface);
public:
    clickatell(QObject *parent=nullptr);
    ~clickatell();

    QString name() 		{ return "clickatell"; }
    QString description()	{ return "The clickatell component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif