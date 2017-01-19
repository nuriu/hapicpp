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
    return baglanti->get("/v1/articles").body;
}

std::string
Hurriyet::haberiGetir(std::string haberKimligi)
{
    return baglanti->get("/v1/articles/" + haberKimligi).body;
}

std::string
Hurriyet::koseYazilariniGetir()
{
    return baglanti->get("/v1/columns").body;
}

std::string
Hurriyet::koseYazisiniGetir(std::string yaziKimligi)
{
    return baglanti->get("/v1/columns/" + yaziKimligi).body;
}

std::string
Hurriyet::tarihleriGetir()
{
    return baglanti->get("/v1/date").body;
}

std::string
Hurriyet::fotografGalerileriniGetir()
{
    return baglanti->get("/v1/newsphotogalleries").body;
}

std::string
Hurriyet::fotografGalerisiniGetir(std::string galeriKimligi)
{
    return baglanti->get("/v1/newsphotogalleries/" + galeriKimligi).body;
}

std::string
Hurriyet::sayfalariGetir()
{
    return baglanti->get("/v1/pages").body;
}

std::string
Hurriyet::sayfayiGetir(std::string sayfaKimligi)
{
    return baglanti->get("/v1/pages/" + sayfaKimligi).body;
}

std::string
Hurriyet::yollariGetir()
{
    return baglanti->get("/v1/paths").body;
}

std::string
Hurriyet::yoluGetir(std::string yolKimligi)
{
    return baglanti->get("/v1/paths/" + yolKimligi).body;
}

std::string
Hurriyet::aramaSonucunuGetir(std::string anahtarKelime)
{
    return baglanti->get("/v1/search/" + anahtarKelime).body;
}

std::string
Hurriyet::yazarlariGetir()
{
    return baglanti->get("/v1/writers").body;
}

std::string
Hurriyet::yazariGetir(std::string yazarKimligi)
{
    return baglanti->get("/v1/writers/" + yazarKimligi).body;
}

Hurriyet::~Hurriyet()
{
    nesneDurumu = false;

    RestClient::disable();
}
