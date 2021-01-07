/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RSS_FEED_TEMPLATE_H
#define RSS_FEED_TEMPLATE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class rss_feed_template : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "rss_feed_template.json");
    Q_INTERFACES(HyPluginInterface);
public:
    rss_feed_template(QObject *parent=nullptr);
    ~rss_feed_template();

    QString name() 		{ return "rss_feed_template"; }
    QString description()	{ return "Support to export sensor values via RSS feed."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void __init__();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif