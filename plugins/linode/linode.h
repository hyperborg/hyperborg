/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LINODE_H
#define LINODE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class linode : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "linode.json");
    Q_INTERFACES(HyPluginInterface);
public:
    linode();
    ~linode();

    QString name() 		{ return "linode"; }
    QString description()	{ return "Support for Linode."; }

protected:
    	void setup();
	void __init__();
	void get_node_id();
	void update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif