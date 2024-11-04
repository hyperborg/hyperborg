#ifndef backup_H
#define backup_H

#include <hyplugin_interface.h>

#include "common.h"
#include "hfsitem.h"
#include "hdevice.h"

#include <QList>
#include <QStringList>
#include <QVariant>

class Job;

class DirContent
{
public:
    DirContent()  {}
    ~DirContent() {}

    QString dircode;                    // Unique code for the 
    QString absolute_path;
    QString mode;
    QStringList allowed_extensions;
    QStringList ignored_extensions;
    int min_mature;                     // Files are not synced if younger than this time period (in minutes)
    int retention;                      // Files are deleted from this directory if older than this and backed up (in minutes)
};

class Backup : public HyPluginInterface, public HDevice
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "backup.json");
    Q_INTERFACES(HyPluginInterface);

public:
    Backup(QObject* parent = nullptr);
    ~Backup();

    QString name() { return "backup"; }
    QString description() { return "Backup driver"; }
    int implementation() { return Developement; }
    QObject* getObject() { return this; }
    QString author() { return "Imre, Nagy <i@hyperborg.com>"; }

    void init();

signals:

public slots:
    QVariant reset(Job *job);                   // Reset the file spider also set limits of query
    QVariant getNextDirectory(Job *job);        // Get the contents of the next directory (also the current index and count of "directories"
    QVariant deleteFile(Job *job);              // Delete a file with a given path
    QVariant changedFiles(Job *job);            // Returns list of the changed files since last query
    QVariant getFileSector(Job *);              // 

private:
    int diridx;                             // working index for "directories"
    int offset;                             // idx offset for removing already processed directories but do not force update dispatched index
    int window;                             // >1 maximum number of directory entries kept in memory

    QList<DirContent> dirs;
    QList<DirContent> watched_dirs;

};

#endif