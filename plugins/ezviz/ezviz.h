/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef EZVIZ_H
#define EZVIZ_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class ezviz : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ezviz.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ezviz();
    ~ezviz();

    QString name() 		{ return "ezviz"; }
    QString description()	{ return "Support for Ezviz devices via Ezviz Cloud API."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif