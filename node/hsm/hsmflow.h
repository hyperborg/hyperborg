#ifndef HSMFLOW_H
#define HSMFLOW_H

#include <QObject>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonValue>

#include "hsmbase.h"
#include "hsmjob.h"
#include "wire.h"

#include "hsmtask.h"
#include "tasks/task_bypass.h"

class HSMFlow : public HSMBase
{
    Q_OBJECT
public:
    HSMFlow(int id, QObject *parent=nullptr);
    ~HSMFlow();

    void clear();
    bool load(QJsonObject obj);
    QJsonObject save(bool states=false);
    void createTest();

    int createTask(int tasktype);

private:
    QHash<int, HSMTask *> tasks;
    QHash<int, Wire *> wires;
};

#endif