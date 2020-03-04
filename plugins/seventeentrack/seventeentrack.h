/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SEVENTEENTRACK_H
#define SEVENTEENTRACK_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class seventeentrack : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "seventeentrack.json");
    Q_INTERFACES(HyPluginInterface);
public:
    seventeentrack();
    ~seventeentrack();

    QString name() 		{ return "seventeentrack"; }
    QString description()	{ return "The seventeentrack component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif