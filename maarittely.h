#ifndef MAARITTELY_H
#define MAARITTELY_H


/** Tietue joka tulee pit‰m‰‰n sis‰ll‰‰n
*   etunimen string -muuttujassa, koulumatkan pituuden floatissa sek‰ hatun
*   koon kokonaislukumuuttujassa. Oletuksena etunimi -j‰sen alustetaan tilaan
*   "empty" jotta voidaan lˆyt‰‰ helposti mik‰ alkio on ns. tyhj‰.
*/
struct Tietue {
    std::string etunimi;
    float koulumatka;
    int hattukoko;
    Tietue(): etunimi("empty"), koulumatka(0.0), hattukoko(0) {}
};

/** Tietuetaulukon koko vakiomuuttujana,
*   boolean TietojaMahtuu muuttuja. Extern koska
*   vaatii otsaketiedostossa
*/
extern const int TIETUE_TAULUN_KOKO;
extern bool TietojaMahtuu;

/** aliohjelmien prototyypit alla */
int Valikko(void);
void TulostaHenkilo(Tietue TIEDOT[]);
void TulostaKaikkiHenkilot(Tietue TIEDOT[], int lkm);
void LisaaHenkilo(Tietue TIEDOT[], int lkm);
void PoistaHenkilo(Tietue TIEDOT[]);
void TallennaTiedostoon(std::string tiedosto, Tietue tietueTaulu[]);
void LueTiedostosta(std::string tiedosto, Tietue tietueTaulu[]);
Tietue katko(const std::string &s, char katkaisin);



#endif