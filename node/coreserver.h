#ifndef CORESERVER_H
#define CORESERVER_H

#include <QObject>

class CoreServer : public QObject
{
Q_OBJECT
public:
    CoreServer(QObject *parent=nullptr) : QObject(parent)  {}
    ~CoreServer() {}
};

#endif