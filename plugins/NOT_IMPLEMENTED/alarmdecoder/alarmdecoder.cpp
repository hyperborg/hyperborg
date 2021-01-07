#include <alarmdecoder.h>

alarmdecoder::alarmdecoder(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","AlarmDecoder");
	manifest.insert("domain","alarmdecoder");
}

alarmdecoder::~alarmdecoder()
{
}

void alarmdecoder::init()
{
}

void alarmdecoder::setup()
{
}


void alarmdecoder::stop_alarmdecoder()
{
}


void alarmdecoder::open_connection()
{
}


void alarmdecoder::handle_closed_connection()
{
}


void alarmdecoder::handle_message()
{
}


void alarmdecoder::handle_rfx_message()
{
}


void alarmdecoder::zone_fault_callback()
{
}


void alarmdecoder::zone_restore_callback()
{
}


void alarmdecoder::handle_rel_message()
{
}


