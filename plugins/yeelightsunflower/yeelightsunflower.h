/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef YEELIGHTSUNFLOWER_H
#define YEELIGHTSUNFLOWER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class yeelightsunflower : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "yeelightsunflower.json");
    Q_INTERFACES(HyPluginInterface);
public:
    yeelightsunflower();
    ~yeelightsunflower();

    QString name() 		{ return "yeelightsunflower"; }
    QString description()	{ return "The yeelightsunflower component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif