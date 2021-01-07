#ifndef ENTITY_H
#define ENTITY_H

#include <common.h>

#include <QObject>
#include <QVariant>
#include <QString>
#include <QList>
#include <QHash>
#include <QHashIterator>

class Slotter;

/*
    The Entity is an object in the HyperBorg system. It provides standadised interface for all kind of devices whether that is logical or physical.
    There are some important rules:
    - The list of Entities are kept identical throughout of a Matrix. It means that all nodes keep its own set of Entities and whenever any attribute
      is changed in the system, all copies are updated. This update mechanism is handled by the HyperBorg basic logic, no special requirement is
      needed.
    - An attribute of an Entity cannot be set directly. When an attribute is set, it is basically an update request. It is packed into a request
      pack and sent to lower layers. If this could be processed on the local UniCore, it is processed there, if not, it would be set to the master
      node's UniCore unit. If the UniCore decides (based on the internal rules and ACLs) that the request is valid, it will generate the new attribute
      set and dispatch it to all nodes. It should be noted, that the new attribute set could be different from what is requested. For example if
      there is a contraint defined for an attribute AC_TEMP  that it should be in a range of (18...30 - for example AC target temperature set) and the
      request contains a value of 5, the generated attribute could be 18. This method protects the whole system from out-of-range or any other way
      wrongly fabricated values.
    - When updating an Entity, we are using delta approach: thus only the modified attributes should be updated, the non-changed ones are copied from
      the current copy. In the rare case where this copy is not required, the disableCopyOfOld() function should be called prior any attribute change.
    - When all attributes are set, the finishUpdateRequest() function should be called to proceed attribute changes (as mentioned before)
*/

class HEntity : public HyObject
{
friend class Slotter;
Q_OBJECT
public:
    HEntity(QString name, QString id, QObject* parent = nullptr) : HyObject(parent)
    {
        _name = name;
        _id = id;
	    _disable_copy = false;
    }

    ~HEntity()
    {
    }

    QString name() { return _name;  }
    QString id() { return _id;      }

    void disableCopyOfOld()
    {
	_disable_copy = true;
    }

    void finishUpdateRequest()
    {
	qDebug() << "ENT::finishUpdateRequest";
	if (!_disable_copy)
	{
	    QHashIterator<QString, QVariant> it(values);
	    while (it.hasNext())
	    {
		it.next();
		if (!reqvalues.contains(it.key()))
		{
		    reqvalues.insert(it.key(), it.value());
		}
	    }
	}
	_disable_copy = false;
	qDebug() << "ENT::HEntityChangeRequested";
        emit HEntityChangeRequested(reqvalues);
    }

    int count() { return values.count(); }

signals:
    void HEntityChanged();
    void HEntityChangeRequested(QHash<QString, QVariant> list);
    void HEntityChanged(QHash<QString, QVariant> list);

public slots:
    void changeRequest(QString id, QVariant v, bool finish)
    {
	qDebug() << "ENT::changeRequest " << id << " " << v << " " << finish;
        reqvalues.insert(id, v);
	if (finish)
	    finishUpdateRequest();
    }

protected slots:
    void changeValues(QHash<QString, QVariant> lst)
    {
	values = lst;
	emit HEntityChanged();
        emit HEntityChanged(values);
    }

private:
    QHash<QString, QVariant> values;		// current values for this HEntity
    QHash<QString, QVariant> reqvalues;		// new values for this HEntity

    bool _disable_copy;
    QString _name;
    QString _id;
};

#endif