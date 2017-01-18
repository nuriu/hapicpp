#include "hurriyet.hpp"

bool      Hurriyet::nesneDurumu = false;
Hurriyet* Hurriyet::nesne       = NULL;

Hurriyet::Hurriyet()
{
    RestClient::init();

    baglanti = new RestClient::Connection("https://api.hurriyet.com.tr/");
    baglanti->FollowRedirects(true);
}

Hurriyet*
Hurriyet::nesneyiGetir()
{
    if(!nesneDurumu) {
        nesne       = new Hurriyet();
        nesneDurumu = true;
        return nesne;
    }
    else
    {
        return nesne;
    }
}

Hurriyet*
Hurriyet::nesneyiGetir(std::string anahtarMetin)
{
    if(!nesneDurumu) {
        nesne       = new Hurriyet();
        nesneDurumu = true;
        return nesne;
    }
    else
    {
        return nesne;
    }
}

std::string
Hurriyet::deneme()
{
    basliklar[ "accept" ] = "application/json";
    basliklar[ "apikey" ] = anahtar;
    baglanti->SetHeaders(basliklar);

    return baglanti->get("/v1/articles").body;
}

Hurriyet::~Hurriyet()
{
    nesneDurumu = false;

    RestClient::disable();
}
