#ifndef LOGIC_H
#define LOGIC_H

#include <QObject>
#include <QList>
#include <QStringList>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonValue>

#include "hsmbase.h"
#include "hsmflow.h"
#include "hsmjob.h"
#include "hsmtask.h"

class Logic : public HSMBase
{
    Q_OBJECT

public:
    Logic(int id, QObject *parent=nullptr);
    ~Logic();

    void clear();
    bool load(QJsonObject obj);
    QJsonObject save(bool states=false);
    void createTest();

private:
    QHash<int, HSMFlow *> flows;


};

#endif