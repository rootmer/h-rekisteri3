/**  Aliohjelmat sis�lt�v� 
*	 cpp-tiedosto
*/

/**  Tarpeellisten kirjastojen k�ytt��notto */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

/**  Erillisen otsaketiedoston sis�llytt�minen */
#include "maarittely.h"

/**  Helpottaa coutin ja cinin k�ytt�� */
using namespace std;

/**  Yksinkertainen valikko n�kyville aliohjelman avulla.
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

/**  Henkil�n lis��miseen tarkoitettu
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
        cout << "Henkil�n koulumatka. Esimerkiksi 4 tai 3.2 tai 11.7." << endl;
        cin >> KouluMatka;
        cout << "Henkil�n hatun koko. Esimerkiksi 32 tai 21." << endl;
        cin >> HatunKoko;
		TIEDOT[kohta].etunimi = EtuNimi;
		TIEDOT[kohta].koulumatka = KouluMatka;
		TIEDOT[kohta].hattukoko = HatunKoko;
        if (kohta == lukumaara - 1) { TietojaMahtuu = true; }
    }

    else if (TietojaMahtuu) { cout << endl << "Taulukko t�ynn�!" << endl; }
}

/**  Aliohjelma joka hakee henkil�n tiedot
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

/**  Listaa kaikki henkil�t lkm kokoisessa
*   tietueessa TIEDOT
*/
void TulostaKaikkiHenkilot(Tietue TIEDOT[], int lkm) {
	for (int a = 0; a < lkm; a++) {
		cout << "Henkil� " << a + 1 << ": " << TIEDOT[a].etunimi << " "
			<< TIEDOT[a].koulumatka << " " << TIEDOT[a].hattukoko << endl;
    }
}

/**  Poistaa henkil�n tiedot
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
				int b = a;
				//for (int b = a; b < TIETUE_TAULUN_KOKO - 1; b++) {
				//	TIEDOT[b].etunimi = TIEDOT[b + 1].etunimi;
				//	TIEDOT[b].koulumatka = TIEDOT[b + 1].koulumatka;
				//	TIEDOT[b].hattukoko = TIEDOT[b + 1].hattukoko;
				
				/**	Siirret��n poistokohtaan seuraava henkil�
				*	ja jatketaan TIEDOT tietuetaulukon loppuun
				*	tai siihen asti kunnes tyhj�t kohdat alkaa
				*/	
				while (TIEDOT[b].etunimi != "empty" && b < TIETUE_TAULUN_KOKO && (b + 1 < TIETUE_TAULUN_KOKO) ) {
					TIEDOT[b].etunimi = TIEDOT[b + 1].etunimi;
					TIEDOT[b].koulumatka = TIEDOT[b + 1].koulumatka;
					TIEDOT[b].hattukoko = TIEDOT[b + 1].hattukoko;
					b++;
				}

				// Poistaa viimesen henkil�n koska siirretty pyk�l� "yl�sp�in"
				TIEDOT[b].etunimi = "empty";
				TIEDOT[b].koulumatka = 0.0;
				TIEDOT[b].hattukoko = 0;
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

/**  Tallentaa taulukon tiedot tiedostoon
*
*/
void TallennaTiedostoon(string tiedosto,Tietue TIEDOT[]) {
	ofstream ofilu(tiedosto);
	if (ofilu.is_open())
	{	
		for (int a = 0; a < TIETUE_TAULUN_KOKO; a++) {
			ofilu << TIEDOT[a].etunimi << " " << TIEDOT[a].koulumatka
				<< " " << TIEDOT[a].hattukoko << endl;
		}
		ofilu.close();
	}
	else cout << "Ei voitu tallentaa tiedostoon: " << tiedosto << "Tarkista onko tiedosto toisen ohjelman k�yt�ss� tai jokin muu ongelma.. " << endl;
}

/**  Lukee tiedot tiedostosta
*	 ja tallentaa ne tietuetaulukkoon
*/
void LueTiedostosta(string tiedosto, Tietue TIEDOT[]) {
	string rivi;
	ifstream ifilu (tiedosto);
	if (ifilu.is_open())
	{
		string erotin = " ";
		int indeksi = 0;
		int erotinkohta = 0;

		/**	K�y rivit l�pi ja 'RiviTieto' tietuetta hyv�ksi
		*	k�ytt�en tiedot tallennettaan TIEDOT tietueeseen
		*/
		while (getline (ifilu,rivi)) {
			cout << rivi << endl;
			Tietue RiviTieto = katko(rivi, ' ');
			TIEDOT[indeksi] = RiviTieto;
			indeksi++;
		}

		/** Jos tietuetaulukko ei ole t�ynn� niin loput merkit��n tyhj�ksi "empty" arvolla */
		for (int a = indeksi; a < TIETUE_TAULUN_KOKO; a++) {
			TIEDOT[a].etunimi = "empty";
			TIEDOT[a].koulumatka = 0.0;
			TIEDOT[a].hattukoko = 0;
		}

		ifilu.close();
	}
	else cout << "Ei voitu avata tiedostoa"; 
}

/** LueTiedosto -aliohjelmaa varten t�llainen p�tk� koodia 
*	joka katkoo string -muuttujan osasiin ja palauttaa osaset
*   n�tisti yhden kokoiseen Tietue -tyyppiseen tietueseen sijoitettuna
*/
Tietue katko(const std::string &s, char katkaisin) {
	Tietue temp[1];
	stringstream ss(s); // Lis�� rivin stringstreamiin
	
	ss >> temp[0].etunimi;
	ss >> temp[0].koulumatka;
	ss >> temp[0].hattukoko;
	
	return temp[0];
}