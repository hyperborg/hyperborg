/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DOVADO_H
#define DOVADO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class dovado : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "dovado.json");
    Q_INTERFACES(HyPluginInterface);
public:
    dovado();
    ~dovado();

    QString name() 		{ return "dovado"; }
    QString description()	{ return "Support for Dovado router."; }

protected:
    	void setup();
	void __init__();
	void name();
	void update();
	void client();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif