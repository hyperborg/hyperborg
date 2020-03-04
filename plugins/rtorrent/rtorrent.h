/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RTORRENT_H
#define RTORRENT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class rtorrent : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "rtorrent.json");
    Q_INTERFACES(HyPluginInterface);
public:
    rtorrent();
    ~rtorrent();

    QString name() 		{ return "rtorrent"; }
    QString description()	{ return "The rtorrent component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif