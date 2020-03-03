#ifndef TESTPLUGIN_H
#define TESTPLUGIn_H

#include <QObject>
#include <QString>

#include <hyplugin.h>

class TestPlugin : public QObject
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.hyperborg.TestPlugin" FILE "testplugin.json");
    Q_INTERFACES(HyPluginInterface);

public:
    QString name() { return "TestPlugin"; }
};


#endif