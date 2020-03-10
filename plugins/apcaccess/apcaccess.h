#ifndef apcaccess_H
#define apcaccess_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QFile>
#include <QProcess>
#include <QDebug>
#include <QTimer>
#include <hyplugin.h>
#include <hyobject.h>

class apcaccess : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "apcaccess.json");
    Q_INTERFACES(HyPluginInterface);

public:
    apcaccess(QObject *parent=nullptr);
    ~apcaccess();

    QString name() 	  { return "apcaccess"; }
    QString description() { return "apcaccess"; }
    int implementation()  { return Developement; }
    QObject *getObject()  { return this;	 }
    void init();

protected slots:
    void queryAPCState();

    void errorOccured(QProcess::ProcessError error);
    void finished(int exitCode, QProcess::ExitStatus exitStatus);
    void readyReadStandardError();
    void readyReadStandardOutput();
    void started();
    void stateChanged(QProcess::ProcessState);

private:
    QString apppath;
    QProcess *process;
    QTimer *timer;


};


#endif