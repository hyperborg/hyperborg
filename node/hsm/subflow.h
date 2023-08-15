#ifndef SUBFLOW_H
#define SUBFLOW_H

#include <QObject>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonValue>

#include "hsmbase.h"
#include "hsmjob.h"
#include "hsmtask.h"
#include "hsmflow.h"

class SubFlow : public HSMBase
{
    Q_OBJECT
public:
    SubFlow(int id, QObject *parent=nullptr);
    ~SubFlow();

    void clear();
    bool load(QJsonObject obj);
    QJsonObject save(bool states=false);
    void createTest();

};

#endif