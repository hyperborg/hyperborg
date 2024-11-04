#include <backupserver.h>
#include "../../node/job.h"

BackupServer::BackupServer(QObject* parent) : HPlugin(parent), HyPluginInterface()
{
}

BackupServer::~BackupServer()
{}


void BackupServer::loadConfiguration(QString str)
{
}
