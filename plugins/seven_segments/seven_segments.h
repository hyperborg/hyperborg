/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SEVEN_SEGMENTS_H
#define SEVEN_SEGMENTS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class seven_segments : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "seven_segments.json");
    Q_INTERFACES(HyPluginInterface);
public:
    seven_segments();
    ~seven_segments();

    QString name() 		{ return "seven_segments"; }
    QString description()	{ return "The seven_segments component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif