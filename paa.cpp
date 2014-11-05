/** Ohjelma joka ottaa vastaan käyttäjältä
*   henkilön perustietoja. Kun taulukko täynnä
*   ohjelma ilmoittaa siitä.
*	Tekijä: Toni Turpeinen
*   Versio: 0.0001a_unstable_experimental
*   PVM: 5.11.2014
*/

#include <iostream>

#include "maarittely.h"

using namespace std;

/** Globaalien muuttujien määrittelyt. Taulukon koko
*   määritetty vakiomuuttujassa. tauluTemp tässä koska
*   osoitinta ei voi määrittää vakion kautta. 
*/
const int taulunKoko = 10;
bool taynna = false;
const string tiedosto = "tiedosto.dat";


/** Ohjelman main funktio
*
*/
int main(void)
{
    /** tietuetaulukon kokona 10 alkiota,
    *   määritetty vakiomuuttujassa taulunkoko
    */
    tietue hRekisteri[taulunKoko];
	int valinta = 99;

    do {

        /** Valikosta poistuminen
        *   syöttämällä 0
        */
        valinta = valikko();
        if (valinta == 0) { break; }

        /** Valikosta valinnalla 1
        *   lisätään henkilötieto
        */
        else if (valinta == 1) {

                LisaaHenkilo(hRekisteri,taulunKoko);
        }

        /** Listaa käyttäjän haluaman
        *   henkilön tiedot
        *
        */
        else if (valinta == 2) {
            TulostaHenkilo(hRekisteri);
        }

        /** Listaa kaikki henkilötiedot
        *   taulukosta
        */
        else if (valinta == 3) {
            TulostaKaikkiHenkilot(hRekisteri, taulunKoko);
        }

		/** Poistaa henkilön tiedot
		*
		*
		*/
		else if (valinta == 4) {
			PoistaHenkilo(hRekisteri);
		}

		else if (valinta == 5) {
			TallennaTiedostoon(tiedosto,hRekisteri);
		}

		/** Tallenna tiedostot tiedostoon
		*
		*
		*
		*/
		else if (valinta == 6) {
			LueTiedostosta(tiedosto,hRekisteri);
		}

        else cout << endl << "Valitse uudelleen" << endl;

    } while (valinta != 0);
}