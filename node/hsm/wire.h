#ifndef WIRE_H
#define WIRE_H

#include <QObject>

#include "hsmbase.h"

class Wire : public HSMBase
{
    Q_OBJECT
public:
    Wire(int id, QObject *parent=nullptr);
    ~Wire();

    void clear();
    bool load(QJsonObject obj);
    QJsonObject save(bool states=false);
    void createTest();

};

#endif