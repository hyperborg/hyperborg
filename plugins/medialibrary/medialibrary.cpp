#include <medialibrary.h>

MediaLibrary::MediaLibrary(QObject *parent) : HyPluginInterface(), HyObject(parent)
{
    init();
}

MediaLibrary::~MediaLibrary()
{
}

void MediaLibrary::init()
{
    qDebug() << hfs->data("config.medialibrary").toString();
}

