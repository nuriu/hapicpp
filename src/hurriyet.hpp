#include <iostream>
#include <string>

#include "restclient-cpp/connection.h"
#include "restclient-cpp/restclient.h"

class Hurriyet
{
  public:
    static Hurriyet* nesneyiGetir();
    static Hurriyet* nesneyiGetir(std::string anahtarMetin);

    std::string              anahtar;
    RestClient::Connection*  baglanti;
    RestClient::HeaderFields basliklar;

    std::string deneme();

    ~Hurriyet();

  private:
    static bool      nesneDurumu;
    static Hurriyet* nesne;
    Hurriyet();
};
