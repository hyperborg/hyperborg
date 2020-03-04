/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SOLAREDGE_H
#define SOLAREDGE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class solaredge : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "solaredge.json");
    Q_INTERFACES(HyPluginInterface);
public:
    solaredge();
    ~solaredge();

    QString name() 		{ return "solaredge"; }
    QString description()	{ return "The solaredge component."; }

protected:
    	void  async_setup();
	void  async_setup_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif