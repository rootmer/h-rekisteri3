/** Ohjelma joka ottaa vastaan käyttäjältä
*   henkilön perustietoja. Etunimi, koulumatkan pituus sekä hatunkoko.
*   Tietojen säilyttämisessä käytetään hyväksi
*   enintään 10 henkilötietoa sisältävää tietuemuotoista taulukkoa. 
*	Tekijä: Toni Turpeinen
*   Versio: 1.0.0
*   PVM: 12.11.2014
*/

/** Tarpeellisen iostream -kirjaston käyttöönotto */
#include <iostream>

/** Erillisen otsaketiedoston sisällyttäminen */
#include "maarittely.h"

/** Nopeuttaa coutien ja cinien käyttöä */
using namespace std;

/** Globaalien muuttujien määrittelyt. Taulukon koko
*   määritetty vakiomuuttujassa 'TIETUE_TAULUN_KOKO'
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
    *   määritetty vakiomuuttujassa TIETUE_TAULUN_KOKO,
	*   alustetaan kokonaislukumuuttuja valinta arvoon 
	*   99.
    */
    Tietue Rekisteri[TIETUE_TAULUN_KOKO];
	int valinta = 99;

    do {

        /** Valikko -aliohjelman kutsu. */
        valinta = Valikko();

		/**Valikosta poistuminen syöttämällä 0. */
        if (valinta == 0) { break; }

        /** Valikosta valinnalla 1 aliohjelmaan
        *   jossa lisätään henkilötieto
        */
        else if (valinta == 1) {
			LisaaHenkilo(Rekisteri,TIETUE_TAULUN_KOKO);
        }

        /** Valinnalla 2 aliohjelmaan joka listaa 
		*   käyttäjän haluaman henkilön tiedot
        */
        else if (valinta == 2) {
            TulostaHenkilo(Rekisteri);
        }

        /** Valinnalla 3 listataan kaikki henkilötiedot
        *   tietuetaulukosta
        */
        else if (valinta == 3) {
            TulostaKaikkiHenkilot(Rekisteri, TIETUE_TAULUN_KOKO);
        }

		/** Poistaa yhden henkilön tiedot tietueesta 'hRekisteri' */
		else if (valinta == 4) {
			PoistaHenkilo(Rekisteri);
		}

		/** Valinta 5 tallentaa syötetyt tiedot 
		*	tietuetaulukosta tiedostoon, jonka tiedostonimen 
		*   vakiomuotoinen string -muuttuja 'TIEDOSTO_NIMI' määrittää.
		*/
		else if (valinta == 5) {
			TallennaTiedostoon(TIEDOSTO_NIMI,Rekisteri);
		}

		/** Valinnalla 6 siirrytään aliohjelmaan LueTiedostosta, jossa yritetään
		*   avata vakioidussa string -muuttujassa 'TIEDOSTO_NIMI' määritetty tiedosto 
		*   ja siirtää tiedot tietuetaulukkoon 'hRekisteri'.
		*/
		else if (valinta == 6) {
			LueTiedostosta(TIEDOSTO_NIMI,Rekisteri);
		}

		/** Jos valinta ei ole sopiva, kehoitetaan käyttäjää uudelleenvalintaan */
        else cout << endl << "Valitse uudelleen" << endl;

	/** Valinnalla 0 ohjelman suorittaminen lopetetaan */
    } while (valinta != 0);
}