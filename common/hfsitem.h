#ifndef HFSITEM_H
#define HFSITEM_H

#include "common.h"

#include <QString>
#include <QList>
#include <QVariant>

class HFS;
class Slotter;

class Listener
{
public:
    Listener();
    ~Listener();

    QString _id;
    int     _ptr;       // int or QObject*?
    QString _token;
    int     _mode;      // When hfsitem changes, should the change be pushed or tell the listener to pull?
    int     _permanent; // If not permanent, the push or pull would remove the entry from the model
};

class Registered
{
public:
    Registered(QObject* targ, QString keyidx, QString fncname = "setElementProperties") : _obj(targ), _func(fncname), _keyidx(keyidx)
    {}
    ~Registered();

    QObject* _obj;
    QString _func;
    QString _keyidx;
    QString token;
};

class HFSItem
{

public:
    friend class HFS;
    friend class Slotter;

    explicit HFSItem(QString id, HFSItem* parentItem = nullptr, int platform = GENERAL, const QVariant& data = QVariant());
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
    int platform() { return _platform;  }
    void setPlatform(int pl) { _platform = pl; }
    void setData(QVariant d);

protected:
    QString _id;		
    QString _path;
    QString _fullpath;
    QString _fullqmlpath;
    int _platform;

    QList<HFSItem*> m_childItems;
    QList<Registered*> registered;         // list of registered objects should be notified when this item changes
					   // and it should be a Listener, not a QObject
    QVariant m_itemData;
    HFSItem* m_parentItem;
};

#endif