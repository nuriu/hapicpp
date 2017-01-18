#include "restclient-cpp/connection.h"
#include "restclient-cpp/restclient.h"

class Hurriyet
{
  public:
    static Hurriyet* nesneyiGetir();
    void             deneme();
    ~Hurriyet() { nesneDurumu = false; }
  private:
    static bool      nesneDurumu;
    static Hurriyet* nesne;
    Hurriyet() {}
};
