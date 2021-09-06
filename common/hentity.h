#ifndef ENTITY_H
#define ENTITY_H

#include <common.h>
#include "hyobject.h"

#include <QObject>
#include <QDebug>
#include <QString>
#include <QList>
#include <QHash>
#include <QHashIterator>
#include <QVariant>

class Slotter;

class HEntity : public HyObject
{
    friend class HEntityFactory;
    friend class Slotter;

    Q_OBJECT
protected:	// Only via factory
    HEntity(QObject *requester,QString name=QString(), QString id=QString(), QObject* parent = nullptr) : HyObject(parent)
    {
        _inupdate = 0;
        _name = name;
        _id = id;
        _requester = requester;
    }

    ~HEntity() {}

    void setName(QString name) { _name = name; 	}
    void setId(QString id)     { _id = id;  	}

    // Serialization/deserializaton happens here. Slotter should not know too much about the internals
    // This way even complex enities could be created on the driver side as long as they provide the 
    // necesseary interface connections

    virtual DataPack *serialize();
    virtual void deserialize(DataPack *pack);

public:
    QString name() 	  { return _name;  }
    QString id() 	  { return _id;    }
    HyObject::Type type() { return HyObject::Entity; }

    HyValue value(QString key=QString());
    HyValue reqValue(QString key=QString());

    void startModification();
    void endModification();

public slots:
    // user side input request
    void setValue(QString key, HyValue value);

signals:
    void setValueChangeRequested(QString id);
    void entityChanged();

private:

    QString  _name;
    QString  _id;
    QHash<QString, HyValue> _values;
    QHash<QString, HyValue> _reqValues;

    HyValue _value;		// duplicate of _values, kept for performance reason
    HyValue _reqValue;

    QObject* _requester;
    int _inupdate;       // when true multiple values are updated
    int _reqSeq;	 // reqest sequence number
};

#endif