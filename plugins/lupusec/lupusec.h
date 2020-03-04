/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LUPUSEC_H
#define LUPUSEC_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class lupusec : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "lupusec.json");
    Q_INTERFACES(HyPluginInterface);
public:
    lupusec();
    ~lupusec();

    QString name() 		{ return "lupusec"; }
    QString description()	{ return "Support for Lupusec Home Security system."; }

protected:
    	void setup();
	void __init__();
	void update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif