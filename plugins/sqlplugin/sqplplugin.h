#ifndef sqlplugin_H
#define sqlplugin_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QFile>
#include <QProcess>

#include <hyplugin.h>
#include <hyobject.h>

class sqlplugin : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "sqlplugin.json");
    Q_INTERFACES(HyPluginInterface);

public:
    sqlplugin(QObject *parent=nullptr);
    ~sqlplugin();

    QString name() 	  { return "sqlplugin"; }
    QString description() { return "sqlplugin"; }
    int implementation()  { return Developement; }
    QObject *getObject()  { return this;	 }
    void init()		  { 			 }

protected slots:



private:
    QString apppath;
    QProcess process;

};


#endif