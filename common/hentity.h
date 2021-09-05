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
    QVariant value()	  { return _value; }
    HyObject::Type type() { return HyObject::Entity; }

    void startModification();
    void endModification();

public slots:
    // user side input request
    void setValue(QVariant value, QVariant unit=QVariant());

signals:
    void setValueChangeRequested(QString id);

protected slots:
    // After requested value is processed, the new value is presented from the mesh
    // if issue is empty value was processed, otherwise issue contans the error 
    // message while it could not be processed (ex range error, etc)
    void setValueAccepted(QVariant value, QVariant unit, QString issue);

signals:
    void valueChanged(QVariant val, QVariant unit);

private:

    QString  _name;
    QString  _id;
    QVariant _value;	// Currently we support only this 
			            // More complex data structures and
			            // input checking would be add later on
    QVariant _unit;
    QVariant _value_req;
    QVariant _unit_req;
    QObject* _requester;
    int _inupdate;       // when true multiple values are updated     
};

#endif