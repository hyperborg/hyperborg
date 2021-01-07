/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef BIZKAIBUS_H
#define BIZKAIBUS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class bizkaibus : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "bizkaibus.json");
    Q_INTERFACES(HyPluginInterface);
public:
    bizkaibus(QObject *parent=nullptr);
    ~bizkaibus();

    QString name() 		{ return "bizkaibus"; }
    QString description()	{ return "The Bizkaibus bus tracker component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif