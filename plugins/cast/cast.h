/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef CAST_H
#define CAST_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class cast : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "cast.json");
    Q_INTERFACES(HyPluginInterface);
public:
    cast();
    ~cast();

    QString name() 		{ return "cast"; }
    QString description()	{ return "Component to embed Google Cast."; }

protected:
    	void  async_setup();
	void  async_setup_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif