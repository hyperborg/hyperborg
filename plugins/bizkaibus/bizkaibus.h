/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef BIZKAIBUS_H
#define BIZKAIBUS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class bizkaibus : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "bizkaibus.json");
    Q_INTERFACES(HyPluginInterface);
public:
    bizkaibus();
    ~bizkaibus();

    QString name() 		{ return "bizkaibus"; }
    QString description()	{ return "The Bizkaibus bus tracker component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif