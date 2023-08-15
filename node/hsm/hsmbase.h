#ifndef HSMBASE_H
#define HSMBASE_H

#include "common.h"

#include <QObject>
#include <QColor>
#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QQueue>

class JobTracker
{
public:
    JobTracker(DataPack *pck=NULL) : pack(pck)
    {
        if (!pack)
            pack = new DataPack();
    }
    ~JobTracker()
    {
        if (pack)
            delete(pack);
    }

    DataPack *pack;
    QHash<QString, QVariant> attributes;
};

class HSMBase : public QObject
{
    Q_PROPERTY(int id MEMBER _id)
    Q_PROPERTY(QString label MEMBER _label)
    Q_PROPERTY(HSMType type MEMBER _type CONSTANT)
    Q_PROPERTY(QColor mainColor MEMBER _mainColor)
    Q_PROPERTY(int trackingLevel MEMBER _trackingLevel)
    Q_PROPERTY(HSMBase* receiver MEMBER _receiver WRITE setReceiver)

    Q_OBJECT
public:
    HSMBase(int id, QObject *parent=nullptr);
    virtual ~HSMBase();

    virtual int id() { return property("id").toInt(); }
    virtual void clear() {}
    virtual bool load(QJsonObject obj)
    {
        _id=obj.value("id").toInt();
        _label=obj.value("label").toString();
        _type=StringToHSMType(obj.value("type").toString());
        return true;
    }

    virtual QJsonObject save(bool states=false)
    {
        QJsonObject retobj;
        retobj.insert("id", QJsonValue(_id));
        retobj.insert("label", _label);
        retobj.insert("type", HSMTypeToString(_type));
        return retobj;
    }

    virtual HSMType type() { return _type; }

    QString HSMTypeToString(HSMType typ);
    HSMType StringToHSMType(QString str);

    virtual void setReceiver(HSMBase *receiver);

public slots:
    virtual void enqueue(JobTracker *jt);

protected slots:
    virtual void process();
    virtual void process(JobTracker *jt);
    virtual void timeStamp(JobTracker *jt, int step);

signals:
    void signal_enqueue(JobTracker *jt);

protected:
    int _id;
    QString _label;
    HSMType _type;
    QColor _mainColor;
    int _trackingLevel;
    HSMBase *_receiver;

    QQueue<JobTracker *> _in_queue;
    QQueue<JobTracker *> _out_queue;
};

#endif