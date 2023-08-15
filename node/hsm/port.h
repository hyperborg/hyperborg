#ifndef PORT_H
#define PORT_H

#include <QObject>
#include <QQueue>

#include "common.h"
#include "hsmbase.h"
#include "wire.h"

class Port : public HSMBase
{
    Q_OBJECT
    Q_PROPERTY(QString sign MEMBER _sign)
    Q_PROPERTY(QString label MEMBER _label)
    Q_PROPERTY(QString src_label MEMBER _src_label);

public:
    Port(int id, QObject *parent);
    virtual ~Port();

    void clear();
    bool load(QJsonObject obj);
    QJsonObject save(bool states=false);

    void process(JobTracker *jt);

private:
    QString _sign;
    QString _label;
    QString _src_label;

};

#endif
