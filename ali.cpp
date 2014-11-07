/** Aliohjelmat sis�lt�v� 
*
*
*/

/** Tarpeellisten kirjastojen k�ytt��notto */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

/** Erillisen otsaketiedoston sis�llytt�minen*/
#include "maarittely.h"

/** Helpottaa coutin ja cinin k�ytt�� */
using namespace std;

/** Yksinkertainen valikko n�kyville aliohjelman avulla.
*   N�ytt�� ohjeet n�yt�ll� ja ottaa vastaan k�ytt�j�n valinnan numerona.
*/
int Valikko(void) {
	int valinta = 99;
    cout << endl;
	cout << "======================================================================" << endl;
    cout << "VALIKKO" << endl;
    cout << "0 - Lopeta" << endl;
    cout << "1 - Lisaa henkilo" << endl;
    cout << "2 - Listaa tietty henkilo" << endl;
    cout << "3 - Listaa kaikki henkilot" << endl;
	cout << "4 - Poista tietyn henkilon tiedot" << endl;
	cout << "5 - Tallenna tiedot tiedostoon" << endl;
	cout << "6 - Lue tiedot tiedostosta" << endl;
	cout << "======================================================================" << endl;
    cin >> valinta;
    return valinta;
}

/** Henkil�n lis��miseen tarkoitettu
*   aliohjelma. Tarkistaa my�s onko tilaa tiedoille.
*/
void LisaaHenkilo(Tietue TIEDOT[], int lukumaara) {
	int kohta = 99;
    for (int a = 0; a < lukumaara; a++) {
		if (TIEDOT[a].etunimi == "empty") {
            kohta = a;
            break;
        }
    }

    if (!TietojaMahtuu) {
        string EtuNimi;
        float KouluMatka;
        int HatunKoko;
        cout << "Henkil�n etunimi" << endl;
        cin >> EtuNimi;
        cout << "Henkil�n koulumatka" << endl;
        cin >> KouluMatka;
        cout << "Henkil�n hatun koko" << endl;
        cin >> HatunKoko;
		TIEDOT[kohta].etunimi = EtuNimi;
		TIEDOT[kohta].koulumatka = KouluMatka;
		TIEDOT[kohta].hattukoko = HatunKoko;
        if (kohta == lukumaara - 1) { TietojaMahtuu = true; }
    }

    else if (TietojaMahtuu) { cout << endl << "Taulukko t�ynn�!" << endl; }
}

/** Aliohjelma joka hakee henkil�n tiedot
*   sy�tetyn nimen perusteella
*/
void TulostaHenkilo(Tietue TIEDOT[]) {
	string nimi;
    cout << "Sy�t� hakemasi henkil�n etunimi" << endl;
    cin >> nimi;

    for (int a = 0; a < TIETUE_TAULUN_KOKO; a++) {
		if (TIEDOT[a].etunimi == nimi) {
			cout << endl << "L�ytyi henkil�: " << TIEDOT[a].etunimi << " " << TIEDOT[a].koulumatka <<
				" " << TIEDOT[a].hattukoko << endl;
            break;
        }

		if (a == TIETUE_TAULUN_KOKO - 1 && TIEDOT[a].etunimi != nimi) {
            cout << endl << "Ei l�ytynyt henkil��: " << nimi << endl;
            break;
        }
    }
}

/** Listaa kaikki henkil�t lkm kokoisessa
*   tietueessa TIEDOT
*
*/
void TulostaKaikkiHenkilot(Tietue TIEDOT[], int lkm) {
	for (int a = 0; a < lkm; a++) {
		cout << "Henkil� " << a << ": " << TIEDOT[a].etunimi << " "
			<< TIEDOT[a].koulumatka << " " << TIEDOT[a].hattukoko << endl;
    }
}

/** Poistaa henkil�n tiedot
*	etunimen perusteella
*/
void PoistaHenkilo(Tietue TIEDOT[]) {
	string nimi;
	string vastaus;
	cout << "Sy�t� henkil�n etunimi jonka tiedot haluat poistaa" << endl;
    cin >> nimi;

    for (int a = 0; a < TIETUE_TAULUN_KOKO; a++) {
		if (TIEDOT[a].etunimi == nimi) {
			cout << endl << "L�ytyi henkil�: " << TIEDOT[a].etunimi << " " << TIEDOT[a].koulumatka <<
				" " << TIEDOT[a].hattukoko << endl;
			cout << "Haluatko poistaa henkil�n tiedot? k/e" << endl;
			cin >> vastaus;
			
			if (vastaus == "k") {
				for (int b = a; b < TIETUE_TAULUN_KOKO - 1; b++) {
					TIEDOT[b].etunimi = TIEDOT[b + 1].etunimi;
					TIEDOT[b].koulumatka = TIEDOT[b + 1].koulumatka;
					TIEDOT[b].hattukoko = TIEDOT[b + 1].hattukoko;
				}
			 }
			
			else if (vastaus == "e") break;
        
		break;
        }

		if ((a == TIETUE_TAULUN_KOKO - 1) && (TIEDOT[a].etunimi != nimi)) {
            cout << endl << "Ei l�ytynyt henkil��: " << nimi << endl;
            break;
        }
    }
}

/** Tallentaa taulukon tiedot tiedostoon
*
*/
void TallennaTiedostoon(string tiedosto,Tietue TIEDOT[]) {
	ofstream ofilu(tiedosto);
	if (ofilu.is_open())
	{	
		for (int a = 0; a < TIETUE_TAULUN_KOKO; a++) {
			ofilu << TIEDOT[a].etunimi << "**" << TIEDOT[a].koulumatka
				<< "**" << TIEDOT[a].hattukoko << endl;
		}
		ofilu.close();
	}
	else cout << "Ei voitu tallentaa tiedostoon: " << tiedosto << "Tarkista onko tiedosto toisen ohjelman k�yt�ss� tai jokin muu ongelma.. " << endl;
}

/** Lukee tiedot tiedostosta
*	ja tallentaa ne tietuetaulukkoon
*/
void LueTiedostosta(string tiedosto, Tietue TIEDOT[]) {
	string rivi;
	ifstream ifilu (tiedosto);
	if (ifilu.is_open())
	{
		string erotin = "**";
		float koulumatkaa;
		int hatunkoko;
		int indeksi = 0;
		while (getline (ifilu,rivi)) {
			cout << rivi << endl;
			string nimi = rivi.substr(0, rivi.find(erotin));
			
			/** Googletettu C++ kirjastossa oleva funktio istringstream 
			*	jolla saadaan tiedot talteen muuttujiin 'koulumatkaa' ja
			*   'hatunkoko'.
			*/
			istringstream(rivi.substr(0, rivi.find(erotin))) >> koulumatkaa;
			istringstream(rivi.substr(0, rivi.find(erotin))) >> hatunkoko;
			// rivi.substr(0, rivi.find(erotin)) >> koulumatkaa;
			// rivi.substr(0, rivi.find(erotin)) >> hatunkoko;

			cout << "\nKoulumatka ja hatunkoko: " << koulumatkaa << " ja "
				<< hatunkoko << endl;
			
			TIEDOT[indeksi].etunimi = nimi;
			TIEDOT[indeksi].koulumatka = koulumatkaa;
			TIEDOT[indeksi].hattukoko = hatunkoko;
			indeksi++;
		}

		for (int a = indeksi; a < TIETUE_TAULUN_KOKO; a++) {
			TIEDOT[a].etunimi = "empty";
			TIEDOT[a].koulumatka = 0.0;
			TIEDOT[a].hattukoko = 0;
		}

		ifilu.close();
	}
	else cout << "Ei voitu avata tiedostoa"; 
}