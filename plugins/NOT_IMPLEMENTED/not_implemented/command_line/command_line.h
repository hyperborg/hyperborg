/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class command_line : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "command_line.json");
    Q_INTERFACES(HyPluginInterface);
public:
    command_line(QObject *parent=nullptr);
    ~command_line();

    QString name() 		{ return "command_line"; }
    QString description()	{ return "The command_line component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif