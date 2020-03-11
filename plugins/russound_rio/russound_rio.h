/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RUSSOUND_RIO_H
#define RUSSOUND_RIO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class russound_rio : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "russound_rio.json");
    Q_INTERFACES(HyPluginInterface);
public:
    russound_rio(QObject *parent=nullptr);
    ~russound_rio();

    QString name() 		{ return "russound_rio"; }
    QString description()	{ return "The russound_rio component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif