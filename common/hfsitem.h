#ifndef HFSITEM_H
#define HFSITEM_H

#include "common.h"

#include <QString>
#include <QList>
#include <QVariant>
#include <QJsonObject>
#include <QJsonValue>

class HFS;
class Slotter;

class Subscriber
{
public:
    Subscriber(QObject* targ, QString keyidx, QString fncname = "valueChanged") : _obj(targ), _func(fncname), _keyidx(keyidx)
    {}
    ~Subscriber() {}

    QObject* _obj;
    QString _keyidx;
    QString _func;
    QString flow_name;
};

class Listener
{
public:
    Listener(QObject* listener, QString key=QString()) : _obj(listener), _keyidx(key)
    {
    }
    ~Listener() {}

    QObject* _obj;
    QString _keyidx;
};

class HFSItem
{
public:
    friend class HFS;
    friend class Slotter;

    explicit HFSItem(QString id, HFSItem* parentItem = nullptr, const QVariant& data = QVariant());
    virtual ~HFSItem();

    void appendChild(HFSItem* child);
    HFSItem* getThis() { return this; }
    HFSItem* child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data() const;
    QObject* object() const;
    int devId() const;
    int row() const;
    HFSItem* parentItem();
    QString id() { return _id; }
    QString path() { return _path; }
    QString fullPath() { return _fullpath; }
    QString fullQMLPath() { return _fullqmlpath; }
    void setData(QVariant d);
    void setObject(QObject* object);
    void setDevId(int devid);

    void loadFromJson(QJsonObject, bool recursive=false);
    QJsonObject saveToJson(bool recursive=false);
    int flags() { return _flags; }
    void setFlags(int flag) { _flags = flag;  }
    void addFlag(int flag) { _flags |= flag;  }

protected:
    QString _id;
    QString _path;
    QString _fullpath;
    QString _fullqmlpath;
    QObject* _object;                       // Object at local node that provides the function
    int _devid;                         // id of the node (device) where the _objcect is located

    int _flags;                             // Stores the HFS generates flags (ex. if provided fully complies with expected interface)
    QVariant m_itemData;

    QList<HFSItem*> m_childItems;
    QList<Subscriber*> subscribers;         // list of registered objects should be notified when this item changes
    HFSItem* m_parentItem;
};

#endif