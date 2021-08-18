#ifndef ENTITY_H
#define ENTITY_H

#include <common.h>
#include "hyobject.h"

#include <QObject>
#include <QVariant>
#include <QString>
#include <QList>
#include <QHash>
#include <QHashIterator>
#include <QVariant>

class Slotter;

class HEntity : public HyObject
{
    friend class HEntityFactory;
    Q_OBJECT
protected:	// Only via factory
    HEntity(QObject *requester,QString name=QString(), QString id=QString(), QObject* parent = nullptr) : HyObject(parent)
    {
        _name = name;
        _id = id;
	    _requester = requester;
    }

    ~HEntity() {}

    void setName(QString name) { _name = name; 	}
    void setId(QString id)     { _id = id;  	}

public:
    QString name() 	  { return _name;  }
    QString id() 	  { return _id;    }
    QVariant value()	  { return _value; }
    HyObject::Type type() { return HyObject::Entity; }

public slots:
    // user side input request
    void setValue(QVariant vale);

signals:
    // change request passed down to the mesh (for processing)
    void setValueRequested(QVariant value, QString id);


protected slots:
    // After requested value is processed, the new value is presented from the mesh
    // if issue is empty value was processed, otherwise issue contans the error 
    // message while it could not be processed (ex range error, etc)
    void setValueAccepted(QVariant value, QString issue);

signals:
    void valueChanged(QVariant val);

private:

    QString  _name;
    QString  _id;
    QVariant _value;	// Currently we support only this 
			// More complex data structures and
			// input checking would be add later on
    QObject* _requester;
};

#endif