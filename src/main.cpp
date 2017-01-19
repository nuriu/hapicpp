#include <fstream>
#include <iostream>
#include <string>

#include "restclient-cpp/connection.h"
#include "restclient-cpp/restclient.h"

#include "json/json.h"

#include "hurriyet.hpp"

int
main()
{
    std::string gecici;

    Hurriyet* h1;
    h1 = Hurriyet::nesneyiGetir();

    std::ifstream anahtarDosyasi("anahtar.cfg");
    if(anahtarDosyasi.is_open()) {
        while(getline(anahtarDosyasi, gecici)) {
            std::cout << "Anahtar bulundu!" << std::endl;
            h1->anahtar = gecici;
        }
        anahtarDosyasi.close();
    }
    else
    {
        std::cout << "Anahtar dosyasi bulunamadi!";
    }

    h1->basliklar[ "accept" ] = "application/json";
    h1->basliklar[ "apikey" ] = h1->anahtar;
    h1->baglanti->SetHeaders(h1->basliklar);

    Json::Value   kok;
    Json::Reader* a;

    a = new Json::Reader();

    a->parse(h1->yazarlariGetir(), kok);

    std::cout << kok << std::endl;

    a->parse(h1->yazariGetir("57a8a3430f25441fb419c54a"), kok);

    std::cout << kok << std::endl;

    return 0;
}
