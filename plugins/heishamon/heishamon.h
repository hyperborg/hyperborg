#ifndef HeishaMon_H
#define HeishaMon_H

#include <QObject>
#include <QtPlugin>
#include <QString>
#include <QDateTime>
#include <QDebug>

#include <QMqttClient>
#include <QMqttAuthenticationProperties>
#include <QMqttUserProperties>
#include <QMqttTopicFilter>

#include "common.h"
#include <hyplugin.h>
#include <hyobject.h>

class HeishaMon : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "heishamon.json");
    Q_INTERFACES(HyPluginInterface);

public:
    HeishaMon(QObject *parent=nullptr);
    ~HeishaMon();

    QString name()          { return "HeishaMon";                               }
    QString description()   { return "HeishaMon diver for Panasonic Aquarea";   }
    int implementation()    { return Developement;                              }
    QObject *getObject()    { return this;                                      }
    QString author()        { return "Imre, Nagy  <i@hyperborg.com>";           }

    void init();

private slots:
    void connected();
    void disconnected();
    void errorChanged(QMqttClient::ClientError err);

private:
    QString leafpoint;
    QMqttUserProperties m_userprop;
    QMqttAuthenticationProperties m_authprop;
    QMqttClient *m_client;

};
#endif
