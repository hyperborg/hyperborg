#include <coinmarketcap.h>

coinmarketcap::coinmarketcap(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","CoinMarketCap");
	manifest.insert("domain","coinmarketcap");
}

coinmarketcap::~coinmarketcap()
{
}

void coinmarketcap::init()
{
}


