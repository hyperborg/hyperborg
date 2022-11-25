#include <speech.h>

Speech::Speech(QObject *parent) : HyPluginInterface(), HyObject(parent)
{
    init();
}

Speech::~Speech()
{
}

void Speech::init()
{
    hfs->subscribe(this, "plugins.speech.say", "say");
    spengine = new QTextToSpeech("");
    log(0, "Available engines: "+spengine->availableEngines().join(" "));
}

void Speech::say(QVariant var)
{
    if (spengine)
    {
	spengine->say(var.toString());
    }
}