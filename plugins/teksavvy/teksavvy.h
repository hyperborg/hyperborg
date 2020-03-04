/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TEKSAVVY_H
#define TEKSAVVY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class teksavvy : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "teksavvy.json");
    Q_INTERFACES(HyPluginInterface);
public:
    teksavvy();
    ~teksavvy();

    QString name() 		{ return "teksavvy"; }
    QString description()	{ return "The teksavvy component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif