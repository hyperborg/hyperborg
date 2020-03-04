/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SONY_PROJECTOR_H
#define SONY_PROJECTOR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class sony_projector : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "sony_projector.json");
    Q_INTERFACES(HyPluginInterface);
public:
    sony_projector();
    ~sony_projector();

    QString name() 		{ return "sony_projector"; }
    QString description()	{ return "The sony_projector component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif