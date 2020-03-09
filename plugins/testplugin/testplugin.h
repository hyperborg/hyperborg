#ifndef TESTPLUGIN_H
#define TESTPLUGIn_H

#include <QObject>
#include <QString>
#include <QtPlugin>

#include <hyplugin.h>
#include <hyobject.h>

class TestPlugin : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "testplugin.json");
    Q_INTERFACES(HyPluginInterface);

public:
    TestPlugin(QObject *parent=nullptr);
    ~TestPlugin();

    QString name() 	  { return "TestPlugin"; }
    QString description() { return "Testplugin"; }
    int implementation()  { return Developement; }
    QObject *getObject()  { return this;	 }
    void init()		  { 			 }
};


#endif