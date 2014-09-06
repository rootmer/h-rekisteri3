/** Ohjelma joka ottaa vastaan k�ytt�j�lt�
*   henkil�n perustietoja. Kun taulukko t�ynn�
*   ohjelma ilmoittaa siit�.
*
*/

#include <iostream>

#include "maarittely.h"

using namespace std;

/** Globaalien muuttujien m��rittelyt. Taulukon koko
*   m��ritetty vakiomuuttujassa. tauluTemp t�ss� koska
*   osoitinta ei voi m��ritt�� vakion kautta. 
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
    *   m��ritetty vakiomuuttujassa taulunkoko
    */
    tietue hRekisteri[taulunkoko];
    int valinta = 99;

    do {

        /** Valikosta poistuminen
        *   sy�tt�m�ll� 0
        */
        valinta = valikko();
        if (valinta == 0) { break; }

        /** Valikosta valinnalla 1
        *   lis�t��n henkil�tieto
        */
        else if (valinta == 1) {

                LisaaHenkilo(hRekisteri,pTauluKoko);
        }

        /** Listaa k�ytt�j�n haluaman
        *   henkil�n tiedot
        *
        */
        else if (valinta == 2) {
            TulostaHenkilo(hRekisteri);
        }

        /** Listaa kaikki henkil�tiedot
        *   taulukosta
        */
        else if (valinta == 3) {
            TulostaKaikkiHenkilot(hRekisteri, taulunkoko);
            /** for (int a = 0; a < taulunkoko; a++) {
            *   cout << "Henkil� " << a << ": " << hRekisteri[a].etunimi << " "
            *   << hRekisteri[a].koulumatka << " " << hRekisteri[a].hattukoko << endl;
            *   }
            */
        }

		/** Poista henkil�n tiedot
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