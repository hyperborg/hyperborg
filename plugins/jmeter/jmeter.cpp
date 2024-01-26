#include <jmeter.h>
#include "../../node/job.h"

JMeter::JMeter(QObject* parent) : HyPluginInterface(), HyObject(parent)
{
}

JMeter::~JMeter()
{}

void JMeter::init()
{
    connectToDatabase();
}

void JMeter::connectToDatabase()
{
    QString db_type = hfs->data("plugins.jmeter.db_type").toString();
    QString db_host = hfs->data("plugins.jmeter.db_host").toString();
    QString db_port = hfs->data("plugins.jmeter.db_port").toString();
    QString db_name = hfs->data("plugins.jmeter.db_name").toString();
    QString db_user = hfs->data("plugins.jmeter.db_user").toString();
    QString db_pass = hfs->data("plugins.jmeter.db_pass").toString();

    qDebug() << " ==================== JMETER INITIALIZATION ==============";
    qDebug() << "\tTYPE: " << db_type;
    qDebug() << "\tHOST: " << db_host;
    qDebug() << "\tPORT: " << db_port;
    qDebug() << "\tNAME: " << db_name;
    qDebug() << "\tUSER: " << db_user;
    qDebug() << "\tPASS: " << db_pass;
    qDebug() << " =========================================================";

    db = QSqlDatabase::addDatabase(db_type);
    db.setHostName(db_host);
    db.setDatabaseName(db_name);
    db.setUserName(db_user);
    db.setPassword(db_pass);
    db.setPort(db_port.toInt());
    bool ok = db.open();

    if (ok)
    {
        qDebug() << "-- opened --";
        _query=new QSqlQuery(db);
    }
    else 
    {
        qDebug() << "database NOT connected";
        qDebug() << db.lastError().text();
    }
}

void JMeter::disconnectFromDatabase()
{
}

QVariant JMeter::query1(Job *job)
{
    qDebug() << "--query1 is called--";
    return QVariant();
}