#ifndef _HURRIYET_HPP
#define _HURRIYET_HPP

#include <iostream>
#include <string>

#include "restclient-cpp/connection.h"
#include "restclient-cpp/restclient.h"

class Hurriyet
{
  public:
    static Hurriyet* nesneyiGetir();

    /**
     * @brief      Hürriyet API Anahtarı.
     */
    std::string anahtar;
    /**
     * @brief      HTTP bağlantısı.
     */
    RestClient::Connection*  baglanti;
    /**
     * @brief      İstek başlıkları.
     */
    RestClient::HeaderFields basliklar;

    std::string haberleriGetir();

    std::string haberiGetir(std::string haberKimligi);

    std::string koseYazilariniGetir();

    std::string koseYazisiniGetir(std::string yaziKimligi);

    std::string tarihleriGetir();

    std::string fotografGalerileriniGetir();

    std::string fotografGalerisiniGetir(std::string galeriKimligi);

    std::string sayfalariGetir();

    std::string sayfayiGetir(std::string sayfaKimligi);

    std::string yollariGetir();

    std::string yoluGetir(std::string yolKimligi);

    std::string aramaSonucunuGetir(std::string anahtarKelime);

    std::string yazarlariGetir();

    std::string yazariGetir(std::string yazarKimligi);

    ~Hurriyet();

  private:
    static bool      nesneDurumu;
    static Hurriyet* nesne;
    Hurriyet();
};

#endif  //_HURRIYET_HPP
