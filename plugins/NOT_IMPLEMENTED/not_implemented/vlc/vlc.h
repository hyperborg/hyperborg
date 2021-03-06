/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef VLC_H
#define VLC_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class vlc : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "vlc.json");
    Q_INTERFACES(HyPluginInterface);
public:
    vlc(QObject *parent=nullptr);
    ~vlc();

    QString name() 		{ return "vlc"; }
    QString description()	{ return "The vlc component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif