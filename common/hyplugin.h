#ifndef HYPLUGIN_H
#define HYPLUGIN_H

#include <QObject>
#include <QString>
#include <QByteArray>

#include "common.h"

// Abstract class for all HyperBorg system plugin
// All plugins should be derived from this one

class HyPlugin : public QObject
{
Q_OBJECT
public:
    HyPlugin(QObject *parent) : QObject(parent) 	
    {}
    virtual ~HyPlugin()	{}

    virtual QString name() 		= 0;
    virtual QString description()	= 0;
    virtual QString author()		= 0;
    virtual QByteArray pluginPicture()  = 0;
    virtual int powerOptions() { return PowerOptions::NonCritical; }
    virtual void setSystemState(SystemStates ss) {}

signals:
    void signal_log(int severity, QString logline);

private:


};

#endif