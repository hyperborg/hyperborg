/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GOOGLE_TRANSLATE_H
#define GOOGLE_TRANSLATE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class google_translate : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "google_translate.json");
    Q_INTERFACES(HyPluginInterface);
public:
    google_translate();
    ~google_translate();

    QString name() 		{ return "google_translate"; }
    QString description()	{ return "The google_translate component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif