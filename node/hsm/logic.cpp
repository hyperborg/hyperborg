#include "logic.h"

Logic::Logic(int id, QObject *parent) : HSMBase(id, parent)
{
    _id = id;
    _type = HSM_Logic;
    createTest();
}

Logic::~Logic()
{
}

void Logic::clear()
{
}

bool Logic::load(QJsonObject obj)
{
    HSMBase::load(obj);
    return true;
}

QJsonObject Logic::save(bool states)
{
    QJsonObject retobj = HSMBase::save(states);
    QJsonArray flowarr;
    for (HSMFlow *flow : flows)
    {
        flowarr.append(flow->save(states));
    }
    retobj["flows"] = flowarr;
    return retobj;
}

void Logic::createTest()
{
    HSMFlow *flow = new HSMFlow(SEQ_NEXTVAL, this);
    flows.insert(flow->id(), flow);
}