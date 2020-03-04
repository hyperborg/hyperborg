#ifndef TESTPLUGIN_H
#define TESTPLUGIn_H

#include <QObject>
#include <QString>
#include <QtPlugin>

#include <hyplugin.h>

class TestPlugin : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "testplugin.json");
    Q_INTERFACES(HyPluginInterface);

public:
    QString name() { return "TestPlugin"; }
    QString description() { return "Testplugin"; }
};


#endif