/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef THINKINGCLEANER_H
#define THINKINGCLEANER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class thinkingcleaner : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "thinkingcleaner.json");
    Q_INTERFACES(HyPluginInterface);
public:
    thinkingcleaner();
    ~thinkingcleaner();

    QString name() 		{ return "thinkingcleaner"; }
    QString description()	{ return "Support for Thinkingcleaner devices."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif