#ifndef HFS_INTERFACE
#define HFS_INTERFACE

#include <common.h>
#include <QObject>

class HFS_Interface
{
public:
    virtual ~HFS_Interface();

    virtual void subscribe(QObject *obj, QString pah, QString funcname=QString("setElementProperty"), QString keyidx=QString()) = 0;
    virtual void unsubscribe(QObject *obj, QString path, QString funcname=QString("setElementProperty")) = 0;
    virtual QString provides(QObject *obj, QString path, int platform, QString keyidx=QString()) = 0;
    virtual QStringList getSubList(QString path) = 0;
    virtual void dataChangeRequest(QString path, QVariant val) = 0;
    virtual QVariant data(QString path) = 0;
    virtual QVariant childKeys(QString path) = 0;

    virtual void log(int severity, QString logline, QString source) = 0;
};

#endif