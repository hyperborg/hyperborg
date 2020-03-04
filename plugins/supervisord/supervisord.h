/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SUPERVISORD_H
#define SUPERVISORD_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class supervisord : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "supervisord.json");
    Q_INTERFACES(HyPluginInterface);
public:
    supervisord();
    ~supervisord();

    QString name() 		{ return "supervisord"; }
    QString description()	{ return "The supervisord component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif