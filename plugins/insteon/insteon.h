/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef INSTEON_H
#define INSTEON_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class insteon : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "insteon.json");
    Q_INTERFACES(HyPluginInterface);
public:
    insteon();
    ~insteon();

    QString name() 		{ return "insteon"; }
    QString description()	{ return "Support for INSTEON Modems (PLM and Hub)."; }

protected:
    	void  async_setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif