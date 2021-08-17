#ifndef HYOBJECT_H
#define HYOBJECT_H

#include <QObject>
#include <QDebug>
#include "hsettings.h"

class HyObject : public QObject
{
public:
    enum Type
    {
        Undefined       = 0,
        CoreServer      = 1,
        UniCore         = 2,
        Slotter         = 3,
        Plugin          = 4,
        Device          = 5,
        Entity          = 6
    };

Q_OBJECT
public:
    HyObject(QObject *parent=nullptr) : QObject(parent) {}
    virtual ~HyObject() {}
    virtual HyObject::Type type() = 0;
    QList<HyObject *> hchildren()
    {
        return findChildren<HyObject *>(QString(), Qt::FindDirectChildrenOnly);
    }

public slots:
    virtual void init() {}

protected slots:
    void log(int severity, QString logline)
    {
        emit signal_log(_id, severity, logline);
    }

signals:
    void signal_log(QString source, int severity, QString logline);

private:
    QString _id;
};

#endif