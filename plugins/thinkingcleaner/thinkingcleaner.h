/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef THINKINGCLEANER_H
#define THINKINGCLEANER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class thinkingcleaner : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "thinkingcleaner.json");
    Q_INTERFACES(HyPluginInterface);
public:
    thinkingcleaner(QObject *parent=nullptr);
    ~thinkingcleaner();

    QString name() 		{ return "thinkingcleaner"; }
    QString description()	{ return "Support for Thinkingcleaner devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif