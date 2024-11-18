#ifndef Speech_H
#define Speech_H

#include <QObject>
#include <QtPlugin>
#include <QString>
#include <QDebug>

#ifdef PF_WASM
#include <QTextToSpeech>
#endif

#include "common.h"
#include "hplugin.h"
#include "hdevice.h"
#include <hyplugin_interface.h>

class Job;

class Speech : public HPlugin, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "speech.json");
    Q_INTERFACES(HyPluginInterface);

public:
    Speech(QObject *parent= nullptr);
    ~Speech();

    QString name()          { return "speech";                                  }
    QString description()   { return "Human speech synthetizer";                }
    int implementation()    { return Developement;                              }
    QObject *getObject()    { return this;                                      }
    QString author()        { return "Imre, Nagy  <i@hyperborg.com>";           }

    void loadConfiguration(QString str);

protected slots:
    void say(Job *job);

private:
#ifdef PF_WASM
    QTextToSpeech *spengine;
#endif

};
#endif
