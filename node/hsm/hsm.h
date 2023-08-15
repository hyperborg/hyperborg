#ifndef HSM_H
#define HSM_H

#include <QObject>
#include <QList>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <QByteArray>

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonValue>

#include "hsmbase.h"
#include "hfs_interface.h"

#include "logic.h"
#include "hsmflow.h"
#include "hsmjob.h"
#include "hsmtask.h"

class HSM : public HSMBase
{
Q_OBJECT
public:
    HSM(int id, QObject *parent=nullptr);
    ~HSM();

public slots:
    void start();                                           // enable event handling and processing
    void freeze();                                          // freezes the machine at the next cycle (ex. dump, states are kept)
    void clear();                                           // clears current internal states, resulting incomplete events

    bool loadLogic(QJsonDocument, bool restore=true);       // loads all logic (flows, etc) from a JSON document, if restore is true and document contains states those would be restored
    bool testLogic(QJsonDocument);                          // test the document if it is parseable and/or fits to the current setup
    QJsonDocument saveLogic(bool states=false);             // saves all logic. If states is TRUE, the current state of the machine is included in the document

    void setTrackingEnabled(int level);                     // 0-disable tracking, otherwise it tracks all packages and their changes (could have performance impact)
                                                            // This globally enables tracking for the whole logic
    void setFlowTrackingEnabled(int flow_id, int level);

    void createTest();

private:
    QHash<int, Logic *> logics;
};

#endif