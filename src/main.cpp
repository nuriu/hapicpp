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
    Json::Value   kok;
    Json::Reader* a;

    std::string gecici;
    std::string anahtar = "";

    std::ifstream anahtarDosyasi("anahtar.cfg");
    if(anahtarDosyasi.is_open()) {
        while(getline(anahtarDosyasi, gecici)) {
            std::cout << "Anahtar bulundu!" << std::endl;
            anahtar = gecici;
        }
        anahtarDosyasi.close();
    }
    else
    {
        std::cout << "Unable to open file";
    }

    RestClient::init();

    RestClient::Connection* conn =
        new RestClient::Connection("https://api.hurriyet.com.tr/");
    conn->FollowRedirects(true);

    RestClient::HeaderFields headers;
    headers[ "accept" ] = "application/json";
    headers[ "apikey" ] = anahtar;
    conn->SetHeaders(headers);

    RestClient::Response r  = conn->get("/v1/articles");
    RestClient::Response r2 = conn->get("/v1/articles/40339699");

    RestClient::disable();

    a = new Json::Reader();
    a->parse(r2.body, kok);

    std::cout << kok << std::endl;

    Hurriyet *h1, *h2;
    h1 = Hurriyet::nesneyiGetir();
    h1->deneme();
    h2 = Hurriyet::nesneyiGetir();
    h2->deneme();

    return 0;
}
