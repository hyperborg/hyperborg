#include <apcaccess.h>

apcaccess::apcaccess(QObject *parent) : HyObject(parent)
{
    apppath="/usr/sbin/apcaccess";
}

apcaccess::~apcaccess()
{
}

void apcaccess::init()
{
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(queryAPCState()));
    timer->start(1000);

    process=new QProcess(this);
    QObject::connect(process, SIGNAL(errorOccured(QProcess::ProcessError)), this, SLOT(errorOccured(QProcess::ProcessError)));
    QObject::connect(process, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(finished(int, QProcess::ExitStatus)));
    QObject::connect(process, SIGNAL(readyReadStandardError()), this, SLOT(readyReadStandardError()));
    QObject::connect(process, SIGNAL(readyReadStandardOutput()), this, SLOT(readyReadStandardOutput()));
    QObject::connect(process, SIGNAL(started()), this, SLOT(started()));
    QObject::connect(process, SIGNAL(stateChanged(QProcess::ProcessState)), this, SLOT(stateChanged(QProcess::ProcessState)));
}

void apcaccess::queryAPCState()
{
    process->start(apppath, QStringList());
}

void apcaccess::errorOccured(QProcess::ProcessError error)
{
    qDebug() << "errorOccured " << error;
}

void apcaccess::finished(int exitCode, QProcess::ExitStatus exitStatus)
{
    qDebug() << "finished: " << exitCode << " " << exitStatus;
}

void apcaccess::readyReadStandardError()
{
    qDebug() << QString(process->readAllStandardError());
}

void apcaccess::readyReadStandardOutput()
{
    QString out = QString(process->readAllStandardOutput());
    QStringList lst = out.split("\n");
    for (int i=0;i<lst.count();++i)
    {
	QString wstr = lst.at(i);
	int io = wstr.indexOf(":");
	if (io!=-1)
	{
	    QString key = wstr.mid(0, io);
	    QString val = wstr.mid(io+1);
	    key = key.simplified();
	    val = val.simplified();
	    qDebug() << "KEY: " << key << "   VALUE: " << val;
	}
    }
}

void apcaccess::started()
{
    qDebug() << "started";
}

void apcaccess::stateChanged(QProcess::ProcessState state)
{
    qDebug() << "stateChanged " << state;
}

