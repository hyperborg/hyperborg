/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef QBITTORRENT_H
#define QBITTORRENT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class qbittorrent : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "qbittorrent.json");
    Q_INTERFACES(HyPluginInterface);
public:
    qbittorrent(QObject *parent=nullptr);
    ~qbittorrent();

    QString name() 		{ return "qbittorrent"; }
    QString description()	{ return "The qbittorrent component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif