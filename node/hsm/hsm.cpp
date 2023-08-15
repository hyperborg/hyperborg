#include "hsm.h"

HSM::HSM(int id, QObject *parent) : HSMBase(id, parent)
{
    _type = HSM_HSM;
    createTest();
}

HSM::~HSM()
{
}

void HSM::start()
{
}

void HSM::freeze()
{
}

void HSM::clear()
{
}

bool HSM::loadLogic(QJsonDocument doc, bool restore)
{
    bool retval = false;
    if (Logic *logic = new Logic(SEQ_NEXTVAL, this))
    {
//        retval = logic->load(doc);
    }
    return retval;
}

bool HSM::testLogic(QJsonDocument doc)
{
    return false;
}

QJsonDocument HSM::saveLogic(bool states)
{
    QJsonDocument doc;
    QJsonObject root=HSMBase::save(states);
    root.insert("1", "2");
    QJsonArray logicarr;
    for (Logic *logic : logics)
    {
        logicarr.append(logic->save(states));
    }
    root["logics"] = logicarr;
    doc.setObject(root);

#if 1
    QFile f("test.json");
    if (f.open(QIODevice::WriteOnly))
    {
        QString str(doc.toJson(QJsonDocument::Indented));
        QTextStream stream(&f);
        stream << str;
        f.close();
    }
#endif
    return doc;
}

void HSM::setTrackingEnabled(int level)
{
}

void HSM::setFlowTrackingEnabled(int flow_id, int level)
{
}

void HSM::createTest()
{
    Logic *logic;
    logic = new Logic(SEQ_NEXTVAL, this);
    logics.insert(logic->id(), logic);
    saveLogic();
}
