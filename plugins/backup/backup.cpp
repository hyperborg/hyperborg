#include <backup.h>
#include "../../node/job.h"

Backup::Backup(QObject* parent) : HyPluginInterface(), HyObject(parent)
{
}

Backup::~Backup()
{}


void Backup::init()
{
    reset(NULL);
}


QVariant Backup::reset(Job *job)
{
    diridx = -1;
    offset = 0;
    window = 0;
    dirs.clear();

    // read settings
    QString bp = basePath();


    return QVariant();
}


QVariant Backup::deleteFile(Job *job)
{
    return QVariant();
}

QVariant Backup::changedFiles(Job *job)
{
    return QVariant();
}

QVariant Backup::getFileSector(Job *)
{
    return QVariant();
}

QVariant Backup::getNextDirectory(Job *job)
{
    if (diridx==-1)
    {
        for (int i=0;i<watched_dirs.count();++i)
        {
            DirContent dc;
            dc.absolute_path = watched_dirs.at(i).absolute_path;
        }
    }
    diridx++;
    QString cdir = "";


    return QVariant();
}


