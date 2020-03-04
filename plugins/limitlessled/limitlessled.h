/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LIMITLESSLED_H
#define LIMITLESSLED_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class limitlessled : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "limitlessled.json");
    Q_INTERFACES(HyPluginInterface);
public:
    limitlessled();
    ~limitlessled();

    QString name() 		{ return "limitlessled"; }
    QString description()	{ return "The limitlessled component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif