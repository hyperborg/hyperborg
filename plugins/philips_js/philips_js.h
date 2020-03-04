/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PHILIPS_JS_H
#define PHILIPS_JS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class philips_js : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "philips_js.json");
    Q_INTERFACES(HyPluginInterface);
public:
    philips_js();
    ~philips_js();

    QString name() 		{ return "philips_js"; }
    QString description()	{ return "The philips_js component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif