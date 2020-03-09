#ifndef badboy_H
#define badboy_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QDebug>
#include <hyplugin.h>
//#include <hyobject.h>

class badboy : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "badboy.json");
    Q_INTERFACES(HyPluginInterface);

public:
    QString name() { return "badboy"; }
    QString description() { return "badboy"; }
    int implementation() { return Developement; }
    QObject *getObject() { return this; }

    void init();

protected:
    void infiniteLoop();
    void nullPtrCall();

    void log(int s, QString logline)
    {
	qDebug() << "BB: " << logline;
    }

};


#endif