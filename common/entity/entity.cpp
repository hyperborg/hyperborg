#include <entity.h>

Entity::Entity(QObject *parent) : QObject(parent)
{}

Entity::~Entity()
{
}

bool Entity::available()
{
    return false;
}

bool Entity::assumedState()
{
    return true;
}

QString Entity::attribution()
{
    return QString();
}

QString Entity::deviceClass()
{
    return QString();
}

QString Entity::deviceInfo()
{
    return QString();
}

QString Entity::entityCategory()
{
    return QString();
}

QString Entity::entityPicture()
{
    return QString();
}

QString Entity::extraStateAttributes()
{
    return QString();
}

bool    Entity::hasEntityName()
{
    return false;
}

QString Entity::name()
{
    return QString();
}

bool Entity::shouldPoll()
{
    return false;
}

QString Entity::uniqueID()
{
    return QString();
}

bool Entity::entityRegistryEnabledDefault()
{
    return false;
}

bool Entity::entityRegistryVisibleDefault()
{
    return false;
}

bool Entity::forceUpdate()
{
    return false;
}

QString Entity::icon()
{
    return QString();
}

