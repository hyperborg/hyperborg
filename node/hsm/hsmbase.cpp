#include "hsmbase.h"

HSMBase::HSMBase(int id, QObject *parent) : QObject(parent), _id(id), _trackingLevel(0), _receiver(NULL)
{
}

HSMBase::~HSMBase()
{
}

QString HSMBase::HSMTypeToString(HSMType typ)
{
    QString retstr;
    int ityp = qBound(0, (int)typ, HSM_LAST-1);
    retstr = HSMTypeStrings.at(ityp);
    return retstr;
}

HSMType HSMBase::StringToHSMType(QString str)
{
    HSMType rettype = HSM_HSMBase;
    int idx = HSMTypeStrings.indexOf(str);
    if (idx!=-1)
        rettype = (HSMType)idx;
    return rettype;
}

void HSMBase::setReceiver(HSMBase *receiver)
{
    if (_receiver)
    {
        QObject::disconnect(this, SIGNAL(signal_enqueue(JobTracker *)), nullptr, nullptr);
        _receiver = NULL;
    }
    if (!receiver) return;
    _receiver = receiver;
    QObject::connect(this, SIGNAL(signal_enqueue(JobTracker *)), _receiver, SLOT(enqueue(JobTracker *)));
}

void HSMBase::enqueue(JobTracker *jt)
{
    if (!jt) return;
    _in_queue.enqueue(jt);
    QMetaObject::invokeMethod(this, "process", Qt::QueuedConnection);
}

void HSMBase::process()
{
    if (!_in_queue.empty())
    {
        if (JobTracker *jt = _in_queue.takeFirst())
        {
            process(jt);
        }
    }
}

void HSMBase::process(JobTracker *jt)
{
    if (!jt) return;
    emit signal_enqueue(jt);
}

void HSMBase::timeStamp(JobTracker *jt, int step)
{
#if 0
    if (id()==0 || id()==10000 /*_trackingLevel || true*/)
    {
        QDateTime dt = QDateTime::currentDateTime();
        qDebug() << dt.toString("yyyy-MM-dd hh:mm:ss.zzz") << " PACKAGE REACHED: # " << id();
    }
#endif
}



