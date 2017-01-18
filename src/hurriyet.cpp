#include "hurriyet.hpp"
#include <iostream>

bool      Hurriyet::nesneDurumu = false;
Hurriyet* Hurriyet::nesne       = NULL;

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

void
Hurriyet::deneme()
{
    std::cout << "deneme" << std::endl;
}
