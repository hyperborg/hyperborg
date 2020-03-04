/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ZIGGO_MEDIABOX_XL_H
#define ZIGGO_MEDIABOX_XL_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class ziggo_mediabox_xl : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ziggo_mediabox_xl.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ziggo_mediabox_xl();
    ~ziggo_mediabox_xl();

    QString name() 		{ return "ziggo_mediabox_xl"; }
    QString description()	{ return "The ziggo_mediabox_xl component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif