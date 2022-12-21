#ifndef Speech_H
#define Speech_H

#include <QObject>
#include <QtPlugin>
#include <QString>
#include <QDebug>
#ifdef WASM
#include <QTextToSpeech>
#endif

#include "common.h"
#include <hyplugin.h>
#include <hyobject.h>

class Speech : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "speech.json");
    Q_INTERFACES(HyPluginInterface);

public:
    Speech(QObject *parent=NULL);
    ~Speech();

    QString name()          { return "speech";                       			}
    QString description()   { return "Human speech synthetizer";                        }
    int implementation()    { return Developement;                      		}
    QObject *getObject()    { return this;                              		}
    QString author()        { return "Imre, Nagy  <i@hyperborg.com>";   		}

    void init();

protected slots:
    void say(QVariant var);

private:
#ifdef WASM
    QTextToSpeech *spengine;
#endif

};
#endif
