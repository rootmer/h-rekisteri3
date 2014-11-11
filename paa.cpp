/** Ohjelma joka ottaa vastaan k�ytt�j�lt�
*   henkil�n perustietoja. Etunimi, koulumatkan pituus sek� hatunkoko.
*   Tietojen s�ilytt�misess� k�ytet��n hyv�ksi
*   enint��n 10 henkil�tietoa sis�lt�v�� tietuemuotoista taulukkoa. 
*	Tekij�: Toni Turpeinen
*   Versio: 1.0.0
*   PVM: 12.11.2014
*/

/** Tarpeellisen iostream -kirjaston k�ytt��notto */
#include <iostream>

/** Erillisen otsaketiedoston sis�llytt�minen */
#include "maarittely.h"

/** Nopeuttaa coutien ja cinien k�ytt�� */
using namespace std;

/** Globaalien muuttujien m��rittelyt. Taulukon koko
*   m��ritetty vakiomuuttujassa 'TIETUE_TAULUN_KOKO'
*/
const int TIETUE_TAULUN_KOKO = 10;
bool TietojaMahtuu = false;
const string TIEDOSTO_NIMI = "tieto_pankki.dat";


/** Ohjelman main funktio
*
*/
int main(void)
{
    /** tietuetaulukon kokona 10 alkiota,
    *   m��ritetty vakiomuuttujassa TIETUE_TAULUN_KOKO,
	*   alustetaan kokonaislukumuuttuja valinta arvoon 
	*   99.
    */
    Tietue Rekisteri[TIETUE_TAULUN_KOKO];
	int valinta = 99;

    do {

        /** Valikko -aliohjelman kutsu. */
        valinta = Valikko();

		/**Valikosta poistuminen sy�tt�m�ll� 0. */
        if (valinta == 0) { break; }

        /** Valikosta valinnalla 1 aliohjelmaan
        *   jossa lis�t��n henkil�tieto
        */
        else if (valinta == 1) {
			LisaaHenkilo(Rekisteri,TIETUE_TAULUN_KOKO);
        }

        /** Valinnalla 2 aliohjelmaan joka listaa 
		*   k�ytt�j�n haluaman henkil�n tiedot
        */
        else if (valinta == 2) {
            TulostaHenkilo(Rekisteri);
        }

        /** Valinnalla 3 listataan kaikki henkil�tiedot
        *   tietuetaulukosta
        */
        else if (valinta == 3) {
            TulostaKaikkiHenkilot(Rekisteri, TIETUE_TAULUN_KOKO);
        }

		/** Poistaa yhden henkil�n tiedot tietueesta 'hRekisteri' */
		else if (valinta == 4) {
			PoistaHenkilo(Rekisteri);
		}

		/** Valinta 5 tallentaa sy�tetyt tiedot 
		*	tietuetaulukosta tiedostoon, jonka tiedostonimen 
		*   vakiomuotoinen string -muuttuja 'TIEDOSTO_NIMI' m��ritt��.
		*/
		else if (valinta == 5) {
			TallennaTiedostoon(TIEDOSTO_NIMI,Rekisteri);
		}

		/** Valinnalla 6 siirryt��n aliohjelmaan LueTiedostosta, jossa yritet��n
		*   avata vakioidussa string -muuttujassa 'TIEDOSTO_NIMI' m��ritetty tiedosto 
		*   ja siirt�� tiedot tietuetaulukkoon 'hRekisteri'.
		*/
		else if (valinta == 6) {
			LueTiedostosta(TIEDOSTO_NIMI,Rekisteri);
		}

		/** Jos valinta ei ole sopiva, kehoitetaan k�ytt�j�� uudelleenvalintaan */
        else cout << endl << "Valitse uudelleen" << endl;

	/** Valinnalla 0 ohjelman suorittaminen lopetetaan */
    } while (valinta != 0);
}