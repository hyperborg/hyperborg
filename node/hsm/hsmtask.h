#ifndef HSMTASK_H
#define HSMTASK_H

#include <QObject>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonValue>

#include <port.h>


class HSMTask : public HSMBase
{
    Q_OBJECT
public:
    HSMTask(int id, QObject *parent = nullptr);
    virtual ~HSMTask();

    virtual int InPortsCount()  { return in_ports.count();  }
    virtual int OutPortsCount() { return out_ports.count(); }

    virtual void init();
    virtual void clear();
    virtual bool load(QJsonObject obj);
    virtual QJsonObject save(bool states=false);

    virtual Port *getPort(bool output=true, int idx=-1);
    virtual void process(JobTracker *jt) {}

protected:
    QList<Port *> in_ports;
    QList<Port *> out_ports;


};

#endif