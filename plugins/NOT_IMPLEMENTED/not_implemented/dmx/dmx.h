#ifndef dmx_H
#define dmx_H

#include <QObject>
#include <QString>
#include <QtPlugin>

#include <hyplugin.h>
#include <hyobject.h>

class dmx : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "dmx.json");
    Q_INTERFACES(HyPluginInterface);

public:
    dmx(QObject *parent=nullptr);
    ~dmx();

    QString name() 	  { return "dmx"; }
    QString description() { return "dmx"; }
    int implementation()  { return Developement; }
    QObject *getObject()  { return this;	 }
    void init()		  { 			 }
};


#endif