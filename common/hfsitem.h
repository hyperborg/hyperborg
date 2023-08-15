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
    Subscriber(QObject* targ, QString keyidx, QString fncname = "setElementProperties") : _obj(targ), _func(fncname), _keyidx(keyidx)
    {}
    ~Subscriber() {}

    QObject* _obj;
    QString _func;
    QString _keyidx;
    QString token;
};

class Listener
{
public:
    Listener(QObject* listener, QString method_name, QString key=QString()) : _obj(listener), _method_name(method_name), _keyidx(key)
    {
    }
    ~Listener() {}

    QObject* _obj;
    QString _method_name;
    QString _keyidx;
};

class HFSItem
{
public:
    friend class HFS;
    friend class Slotter;

    explicit HFSItem(QString id, HFSItem* parentItem = nullptr, Platforms platform = GENERAL, const QVariant& data = QVariant());
    virtual ~HFSItem();

    void appendChild(HFSItem* child);
    HFSItem* getThis() { return this; }
    HFSItem* child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data() const;
    int row() const;
    HFSItem* parentItem();
    QString id() { return _id; }
    QString path() { return _path; }
    QString fullPath() { return _fullpath; }
    QString fullQMLPath() { return _fullqmlpath; }
    Platforms platform() { return _platform;  }
    void setPlatform(Platforms pl) { _platform = pl; }
    void setData(QVariant d);
    void callMethod();

    void loadFromJson(QJsonObject, bool recursive=false);
    QJsonObject saveToJson(bool recursive=false);
    int flags() { return _flags; }
    void setFlags(int flag) { _flags = flag;  }

protected:
    QString _id;
    QString _path;
    QString _fullpath;
    QString _fullqmlpath;

    Platforms _platform;
    int _flags;                             // Stores the HFS generates flags (ex. if provided fully complies with expected interface)
    QVariant m_itemData;
    QList<Listener*> methods;             // Sequence of listeners should be called when this Item (if flag is method) is called

    QList<HFSItem*> m_childItems;
    QList<Subscriber*> subscribers;         // list of registered objects should be notified when this item changes
    HFSItem* m_parentItem;
};

#endif