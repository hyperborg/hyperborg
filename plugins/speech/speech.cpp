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
#ifdef WASM
    spengine = new QTextToSpeech("");
    log(Info, "Available engines: "+spengine->availableEngines().join(" "));
#endif
}

void Speech::say(QVariant var)
{
#ifdef WASM
    if (spengine)
    {
	spengine->say(var.toString());
    }
#endif
}