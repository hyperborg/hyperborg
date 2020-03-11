#ifndef ENTITY_H
#define ENTITY_H

#include <common.h>

#include <QObject>

class Entity : public QObject
{
Q_OBJECT
public:
    Entity(QObject *parent=nullptr);
    ~Entity();


};

#endif