#include "hurriyet.hpp"

bool      Hurriyet::nesneDurumu = false;
Hurriyet* Hurriyet::nesne       = NULL;


Hurriyet::Hurriyet()
{
    RestClient::init();

    baglanti = new RestClient::Connection("https://api.hurriyet.com.tr/");
    baglanti->FollowRedirects(true);
}

/**
 * @brief      Nesne oluşturma ve temin etme işlemlerinden sorumludur.
 *
 * @return     Oluşturulmuş nesneyi döndürür.
 */
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

/**
 * @brief      API tarafından sunulan haberleri çağırır.
 *
 * @return     İsteğe verilen cevabı döndürür.
 */
std::string
Hurriyet::haberleriGetir()
{
    return baglanti->get("/v1/articles").body;
}

/**
 * @brief      API tarafından sunulan, belirtilen kimliğe sahip haberi çağırır.
 *
 * @param[in]  haberKimligi  haber kimliği
 *
 * @return     İsteğe verilen cevabı döndürür.
 */
std::string
Hurriyet::haberiGetir(std::string haberKimligi)
{
    return baglanti->get("/v1/articles/" + haberKimligi).body;
}

/**
 * @brief      API tarafından sunulan köşe yazılarını çağırır.
 *
 * @return     İsteğe verilen cevabı döndürür.
 */
std::string
Hurriyet::koseYazilariniGetir()
{
    return baglanti->get("/v1/columns").body;
}

/**
 * @brief      API tarafından sunulan, belirtilen kimliğe sahip köşe yazısını
 * çağırır.
 *
 * @param[in]  yaziKimligi  yazi kimliği
 *
 * @return     İsteğe verilen cevabı döndürür.
 */
std::string
Hurriyet::koseYazisiniGetir(std::string yaziKimligi)
{
    return baglanti->get("/v1/columns/" + yaziKimligi).body;
}

/**
 * @brief      API tarafından sunulan tarihi çağırır.
 *
 * @return     İsteğe verilen cevabı döndürür.
 */
std::string
Hurriyet::tarihleriGetir()
{
    return baglanti->get("/v1/date").body;
}

/**
 * @brief      API tarafından sunulan fotoğraf galerilerini çağırır.
 *
 * @return     İsteğe verilen cevabı döndürür.
 */
std::string
Hurriyet::fotografGalerileriniGetir()
{
    return baglanti->get("/v1/newsphotogalleries").body;
}

/**
 * @brief      API tarafından sunulan, belirtilen kimliğe sahip fotoğraf
 * galerisini çağırır.
 *
 * @param[in]  galeriKimligi  galeri kimliği
 *
 * @return     İsteğe verilen cevabı döndürür.
 */
std::string
Hurriyet::fotografGalerisiniGetir(std::string galeriKimligi)
{
    return baglanti->get("/v1/newsphotogalleries/" + galeriKimligi).body;
}

/**
 * @brief      API tarafından sunulan sayfaları çağırır.
 *
 * @return     İsteğe verilen cevabı döndürür.
 */
std::string
Hurriyet::sayfalariGetir()
{
    return baglanti->get("/v1/pages").body;
}

/**
 * @brief      API tarafından sunulan, belirtilen kimliğe sahip sayfayı çağırır.
 *
 * @param[in]  sayfaKimligi  sayfa kimliği
 *
 * @return     İsteğe verilen cevabı döndürür.
 */
std::string
Hurriyet::sayfayiGetir(std::string sayfaKimligi)
{
    return baglanti->get("/v1/pages/" + sayfaKimligi).body;
}

/**
 * @brief      API tarafından sunulan yolları çağırır.
 *
 * @return     İsteğe verilen cevabı döndürür.
 */
std::string
Hurriyet::yollariGetir()
{
    return baglanti->get("/v1/paths").body;
}

/**
 * @brief      API tarafından sunulan, belirtilen kimliğe sahip yolu çağırır.
 *
 * @param[in]  yolKimligi  yol kimliği
 *
 * @return     İsteğe verilen cevabı döndürür.
 */
std::string
Hurriyet::yoluGetir(std::string yolKimligi)
{
    return baglanti->get("/v1/paths/" + yolKimligi).body;
}

/**
 * @brief      Belirtilen kelime ile yapılmış aramanın sonuçlarını çağırır.
 *
 * @param[in]  anahtarKelime  anahtar kelime
 *
 * @return     İsteğe verilen cevabı döndürür.
 */
std::string
Hurriyet::aramaSonucunuGetir(std::string anahtarKelime)
{
    return baglanti->get("/v1/search/" + anahtarKelime).body;
}

/**
 * @brief      API tarafından sunulan yazarları çağırır.
 *
 * @return     İsteğe verilen cevabı döndürür.
 */
std::string
Hurriyet::yazarlariGetir()
{
    return baglanti->get("/v1/writers").body;
}

/**
 * @brief      API tarafından sunulan, belirtilen kimliğe sahip yazarı çağırır.
 *
 * @param[in]  yazarKimligi  yazar kimliği
 *
 * @return     İsteğe verilen cevabı döndürür.
 */
std::string
Hurriyet::yazariGetir(std::string yazarKimligi)
{
    return baglanti->get("/v1/writers/" + yazarKimligi).body;
}

/**
 * @brief      Hürriyet nesnesini yok eder.
 */
Hurriyet::~Hurriyet()
{
    nesneDurumu = false;

    RestClient::disable();
}
