/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class keyboard : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "keyboard.json");
    Q_INTERFACES(HyPluginInterface);
public:
    keyboard();
    ~keyboard();

    QString name() 		{ return "keyboard"; }
    QString description()	{ return "Support to emulate keyboard presses on host machine."; }

protected:
    	void setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif