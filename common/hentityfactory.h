#ifndef HENTITYFACTORY_H
#define HENTITYFACTORY_H

#include "hentity.h"

#include <QObject>
#include <QList>
#include <QMutex>
#include <QMutexLocker>
#include <QMultiHash>

class HEntityFactory : public QObject
{
Q_OBJECT
public:
    HEntityFactory(QObject *parent=nullptr);
    ~HEntityFactory();

    HEntity *create(QString name, QObject *requester);
    void destroy(HEntity *entity);

public slots:

private slots:
    void requesterDestroyed(QObject *obj);
    void entityDestroyed(QObject *obj);
    

signals:
    void entityCreated(QString name);
    void entityDestroyed(QString name);

private:
    QMutex mutex;
    QMultiHash<QString, HEntity *> entities;
    QList<QObject*> requesters;
    int id;

};

#endif