/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GSTREAMER_H
#define GSTREAMER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class gstreamer : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "gstreamer.json");
    Q_INTERFACES(HyPluginInterface);
public:
    gstreamer();
    ~gstreamer();

    QString name() 		{ return "gstreamer"; }
    QString description()	{ return "The gstreamer component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif