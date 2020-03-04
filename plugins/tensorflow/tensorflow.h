/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TENSORFLOW_H
#define TENSORFLOW_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class tensorflow : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "tensorflow.json");
    Q_INTERFACES(HyPluginInterface);
public:
    tensorflow();
    ~tensorflow();

    QString name() 		{ return "tensorflow"; }
    QString description()	{ return "The tensorflow component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif