#include <fstream>
#include <iostream>
#include <string>

#include "restclient-cpp/connection.h"
#include "restclient-cpp/restclient.h"

int
main()
{
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
    else {
        std::cout << "Unable to open file";
    }

    RestClient::init();

    RestClient::Connection* conn =
        new RestClient::Connection("https://api.hurriyet.com.tr/v1/articles");
    conn->FollowRedirects(true);

    RestClient::HeaderFields headers;
    headers[ "accept" ] = "application/json";
    headers[ "apikey" ] = anahtar;
    conn->SetHeaders(headers);

    RestClient::Response r = conn->get("/");

    RestClient::disable();

    std::cout << r.body << std::endl;

    return 0;
}
