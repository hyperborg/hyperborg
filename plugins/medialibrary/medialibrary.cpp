#include <medialibrary.h>

MediaLibraryDevice::MediaLibraryDevice() : rndgen(nullptr)
{
    rndgen = QRandomGenerator::system();
    if (!rndgen)
    {
#if 0
    quint32 seedBuffer;
    int len = 32;
    std::seed_seq sseq(seedBuffer, seedBuffer + len);
    rndgen = new QRandomGenerator(seedBuffer);
#endif
    }
    qDebug() << "RNDGEN: " << rndgen;
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(timedUpdate()));
    timer.setSingleShot(false);
    init();
}

MediaLibraryDevice::~MediaLibraryDevice()
{
}

void MediaLibraryDevice::init()
{
    rootDir="/usr/src/test";
    refresh_timeout = 60;
    timer.stop();
    if (refresh_timeout>0)
    {
    timer.start(refresh_timeout);
    }
}

void MediaLibraryDevice::timedUpdate()
{
    pushRandomFile();
}

void MediaLibraryDevice::pushRandomFile()
{
    if (rootDir.isEmpty()) return;
    if (!rndgen) return;
    QDir dir(rootDir);
    if (!dir.exists()) return;

    bool found=false;
    QString foundpath;
    while(!found)
    {
    QFileInfoList lst = dir.entryInfoList(QDir::Files | QDir::AllDirs | QDir::NoDotAndDotDot  );
    if (lst.count())
    {
        int idx = rndgen->bounded(lst.count());
        QFileInfo fi = lst.at(idx);
        if (fi.isFile())
        {
        found = true;
        foundpath = fi.absoluteFilePath();
        }
        else if (fi.isDir())
        {
        dir.cd(fi.fileName());
        }
        else
        {
        found = true;
        }
    }
    else
    {
        found = true;
    }
    }

    if (!foundpath.isEmpty())   // actually found a file, not aborted
    {
        qDebug() << "WOULD PUSH MEDIA FILE: " << foundpath;
        QFile f(foundpath);
        if (f.open(QIODevice::ReadOnly))
        {
        f.close();
        }
    }
}

// ======================================== MEDIALIBRARY ==================================================

MediaLibrary::MediaLibrary(QObject *parent) : HyPluginInterface(), HDevice(parent)
{
    init();
}

MediaLibrary::~MediaLibrary()
{
}

void MediaLibrary::init()
{
}

