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
    Registered(QObject* targ, int mode = 0, QString fncname = "setElementProperties") : _obj(targ), _func(fncname), _mode(mode)
    {}
    ~Registered();

    QObject* _obj;
    QString _func;
    int _mode;
};

class HFSItem
{

public:
    friend class HFS;
    friend class Slotter;

    explicit HFSItem(QString id, HFSItem* parentItem = nullptr, const QList<QVariant>& data = QList<QVariant>());
    virtual ~HFSItem();

    void appendChild(HFSItem* child);
    HFSItem* getThis() { return this; }

    HFSItem* child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    HFSItem* parentItem();
    QString id() { return _id;}
    QString path() { return _path; }
    QString fullPath() { return _fullpath; }
    void setData(QVariant d, int col = 0);
    QVariant data(int column = 0);

protected:
    QString _id;		
    QString _path;
    QString _fullpath;

    QList<HFSItem*> m_childItems;
    QList<Registered*> registered;         // list of registered objects should be notified when this item changes
					   // and it should be a Listener, not a QObject
    QList<QVariant> m_itemData;
    HFSItem* m_parentItem;
};

#endif