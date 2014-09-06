/** Ohjelma joka ottaa vastaan käyttäjältä
*   henkilön perustietoja. Kun taulukko täynnä
*   ohjelma ilmoittaa siitä.
*
*/

#include <iostream>

#include "maarittely.h"

using namespace std;

/** Globaalien muuttujien määrittelyt. Taulukon koko
*   määritetty vakiomuuttujassa. tauluTemp tässä koska
*   osoitinta ei voi määrittää vakion kautta. 
*/
const int taulunkoko = 10;
int tauluTemp = taulunkoko;
int *pTauluKoko = &tauluTemp;
bool taynna = false;


/** Ohjelman main funktio
*
*/
int main(void)
{
    /** tietuetaulukon kokona 10 alkiota,
    *   määritetty vakiomuuttujassa taulunkoko
    */
    tietue hRekisteri[taulunkoko];
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

                LisaaHenkilo(hRekisteri,pTauluKoko);
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
            TulostaKaikkiHenkilot(hRekisteri, taulunkoko);
            /** for (int a = 0; a < taulunkoko; a++) {
            *   cout << "Henkilö " << a << ": " << hRekisteri[a].etunimi << " "
            *   << hRekisteri[a].koulumatka << " " << hRekisteri[a].hattukoko << endl;
            *   }
            */
        }

		/** Poista henkilön tiedot
		*
		*
		*/
		else if (valinta == 4) {

		}

		/** Tallenna tiedostot tiedostoon
		*
		*
		*
		*/
		else if (valinta == 5) {

		}

		/** Hae tiedot tiedostosta
		*
		*
		*/
		else if (valinta == 6) {

		}

        else cout << endl; << "Valitse uudelleen" << endl;

    } while (valinta != 0);
}