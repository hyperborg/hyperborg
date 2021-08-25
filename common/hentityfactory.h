#ifndef HENTITYFACTORY_H
#define HENTITYFACTORY_H

#include "hentity.h"

#include <QCoreApplication>
#include <QObject>
#include <QList>
#include <QMutex>
#include <QMutexLocker>
#include <QMultiHash>

class Slotter;

class HEntityFactory : public QObject
{
    friend class Slotter;
Q_OBJECT
public:
    static void initialize();
    static HEntityFactory *getInstance();
    ~HEntityFactory();

    HEntity *create(QString name, QObject *requester=nullptr);
    void enroll(HEntity *entity);
    void destroy(HEntity *entity);
    HEntity *get(QString id);

protected:
    void setSlotter(QObject *obj);

public slots:

private slots:
    void requesterDestroyed(QObject *obj);
    void entityDestroyed(QObject *obj);

signals:
    void entityCreated(QString name);
    void entityDestroyed(QString name);

private:
    HEntityFactory(QObject *parent=nullptr);

private:
    QMutex mutex;
    QMultiHash<QString, HEntity *> entities;
    QList<QObject*> requesters;
    int id;

    QObject *slotter;

};

#endif