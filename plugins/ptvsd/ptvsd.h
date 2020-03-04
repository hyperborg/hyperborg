/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PTVSD_H
#define PTVSD_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class ptvsd : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ptvsd.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ptvsd();
    ~ptvsd();

    QString name() 		{ return "ptvsd"; }
    QString description()	{ return ""; }

protected:
    	void async_setup();
	void waitfor();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif