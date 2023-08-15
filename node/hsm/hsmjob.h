#ifndef HSMJOB_H
#define HSMJOB_H

#include <QObject>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonValue>

#include "hsmbase.h"
#include "hsmtask.h"

class HSMJob : public HSMBase
{
    Q_OBJECT
public:
    HSMJob(int id, QObject *parent = nullptr);
    ~HSMJob();

    void clear();
    bool load(QJsonObject obj);
    QJsonObject save(bool states=false);
    void createTest();

private:

};

#endif