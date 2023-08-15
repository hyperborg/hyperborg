#ifndef HUDFactory_H
#define HUDFactory_H

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QGraphicsScene>
#include <QList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QFile>

#include "huditem.h"
#include "hudport.h"
#include "hudwire.h"
#include "hudtext.h"
#include "hudtask.h"

class HyScene;

class HUDFactory : public QObject
{
Q_OBJECT
public:
    HUDFactory(QObject *parent=nullptr);
    ~HUDFactory();

    HUDItem* create(int type, QGraphicsItem *parent=nullptr);
    HUDItem* create(QJsonObject obj, QGraphicsItem *parent=nullptr);

    void setScene(HyScene *scene);

    bool save(QString filename);
    QJsonDocument saveAll();

    bool load(QString filename);
    bool loadAll(QJsonDocument doc);

public slots:
    void clear();

private:
    HyScene *scene;
};

#endif

