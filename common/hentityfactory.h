#ifndef HENTITYFACTORY_H
#define HENTITYFACTORY_H

#include "hentity.h"

#include <QCoreApplication>
#include <QObject>
#include <QList>
#include <QMutex>
#include <QMutexLocker>
#include <QMultiHash>
#include <QWaitCondition>

class Slotter;

class HEntityFactory : public QObject
{
	friend class Slotter;
Q_OBJECT
public:
    static void initialize();
    static HEntityFactory *getInstance();
    ~HEntityFactory();

    HEntity *get(QString name);
    void enroll(HEntity *entity);
    void destroy(HEntity *entity);

private slots:
	void changeRequested(QString name);
    void entityDestroyed(QObject *obj);

signals:
    void entityCreated(QString name);
    void entityDestroyed(QString name);
    void newPackReady(DataPack* p);

private:
    HEntityFactory(QObject *parent=nullptr);

private:
    QMutex mutex;
    QMultiHash<QString, HEntity *> entities;
};

#endif