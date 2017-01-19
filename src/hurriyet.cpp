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
Hurriyet::haberleriGetir()
{
    basliklar[ "accept" ] = "application/json";
    basliklar[ "apikey" ] = anahtar;
    baglanti->SetHeaders(basliklar);

    return baglanti->get("/v1/articles").body;
}

std::string
Hurriyet::haberiGetir(std::string haberKimligi)
{
    return NULL;
}

std::string
Hurriyet::koseYazilariniGetir()
{
    return NULL;
}

std::string
Hurriyet::koseYazisiniGetir(std::string yaziKimligi)
{
    return NULL;
}

std::string
Hurriyet::tarihleriGetir()
{
    return NULL;
}

std::string
Hurriyet::fotografGalerileriniGetir()
{
    return NULL;
}

std::string
Hurriyet::fotografGalerisiniGetir(std::string galeriKimligi)
{
    return NULL;
}

std::string
Hurriyet::sayfalariGetir()
{
    return NULL;
}

std::string
Hurriyet::sayfayiGetir(std::string sayfaKimligi)
{
    return NULL;
}

std::string
Hurriyet::yollariGetir()
{
    return NULL;
}

std::string
Hurriyet::yoluGetir(std::string yolKimligi)
{
    return NULL;
}

std::string
Hurriyet::aramaSonucunuGetir(std::string anahtarKelime)
{
    return NULL;
}

std::string
Hurriyet::yazarlariGetir()
{
    return NULL;
}

std::string
Hurriyet::yazariGetir(std::string yazarKimligi)
{
    return NULL;
}

Hurriyet::~Hurriyet()
{
    nesneDurumu = false;

    RestClient::disable();
}
