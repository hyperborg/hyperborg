/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LINKSYS_SMART_H
#define LINKSYS_SMART_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class linksys_smart : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "linksys_smart.json");
    Q_INTERFACES(HyPluginInterface);
public:
    linksys_smart();
    ~linksys_smart();

    QString name() 		{ return "linksys_smart"; }
    QString description()	{ return "The linksys_smart component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif