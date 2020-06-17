#ifndef ENTITY_H
#define ENTITY_H

#include <common.h>

#include <QObject>
#include <QVariant>
#include <QString>

class Entity : public QObject
{
Q_OBJECT
public:
    Entity(QString name, QString id, QObject* parent = nullptr)
    {
        _name = name;
        _id = id;
    }
   
    ~Entity()
    {
    }

    QString name() { return _name;  }
    QString id() { return _id;      }

signals:
    void entityChangeRequested(QVariant v);
    void entityChanged(QVariant v);

public slots:
    void changeRequest(QVariant v)
    {
        _value = v;
        emit entityChangeRequested(v);
    }

protected slots:
    void changeValue(QVariant v)
    {
        emit entityChanged(v);
    }
private:
    QVariant _req_value;
    QVariant _value;
    QString _name;
    QString _id;
};

#endif