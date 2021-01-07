#include <viaggiatreno.h>

viaggiatreno::viaggiatreno(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Trenitalia ViaggiaTreno");
	manifest.insert("domain","viaggiatreno");
}

viaggiatreno::~viaggiatreno()
{
}

void viaggiatreno::init()
{
}


