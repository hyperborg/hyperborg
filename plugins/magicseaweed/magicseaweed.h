/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MAGICSEAWEED_H
#define MAGICSEAWEED_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class magicseaweed : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "magicseaweed.json");
    Q_INTERFACES(HyPluginInterface);
public:
    magicseaweed();
    ~magicseaweed();

    QString name() 		{ return "magicseaweed"; }
    QString description()	{ return "The magicseaweed component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif