#include <iostream>
#include <fstream>
#include <string>

#include "maarittely.h"


using namespace std;

/** Valikko näkyville
*   nyt aliohjelmana
*/
int valikko(void) {
	int valinta = 99;
    cout << endl;
    cout << "VALIKKO" << endl;
    cout << "0 - Lopeta" << endl;
    cout << "1 - Lisaa henkilo" << endl;
    cout << "2 - Listaa tietty henkilo" << endl;
    cout << "3 - Listaa kaikki henkilot" << endl;
	cout << "4 - Poista tietyn henkilon tiedot" << endl;
	cout << "5 - Tallenna tiedot tiedostoon" << endl;
	cout << "6 - Lue tiedot tiedostosta" << endl;
    cin >> valinta;
    return valinta;
}

/** Aliohjelma joka hakee henkilön tiedot
*   syötetyn nimen perusteella
*/
void TulostaHenkilo(tietue TIEDOT[]) {
	string nimi;
    cout << "Syötä hakemasi henkilön etunimi" << endl;
    cin >> nimi;

    for (int a = 0; a < taulunKoko; a++) {
        if (TIEDOT[a].etunimi == nimi) {
            cout << endl << "Löytyi henkilö: " << TIEDOT[a].etunimi << " " << TIEDOT[a].koulumatka <<
            " " << TIEDOT[a].hattukoko << endl;
            break;
        }

        if (a == taulunKoko - 1 && TIEDOT[a].etunimi != nimi) {
            cout << endl << "Ei löytynyt henkilöä: " << nimi << endl;
            break;
        }
    }
}

/** Listaa kaikki henkilöt lkm kokoisessa
*   tietuetaulukossa TIEDOT
*
*/
void TulostaKaikkiHenkilot(tietue TIEDOT[], int lkm) {
	for (int a = 0; a < lkm; a++) {
        cout << "Henkilö " << a << ": " << TIEDOT[a].etunimi << " "
        << TIEDOT[a].koulumatka << " " << TIEDOT[a].hattukoko << endl;
    }
}

/** Henkilön lisäämiseen tarkoitettu
*   aliohjelma. Tarkistaa myös onko tilaa tiedoille.
*/
void LisaaHenkilo(tietue TIEDOT[], int *lkm) {
	int kohta = 99;
    for (int a = 0; a < *lkm; a++) {
        if (TIEDOT[a].etunimi == "empty") {
            kohta = a;
            break;
        }
    }

    if (!taynna) {
        string eNimi;
        float kMatka;
        int hKoko;
        cout << "Henkilön etunimi" << endl;
        cin >> eNimi;
        cout << "Henkilön koulumatka" << endl;
        cin >> kMatka;
        cout << "Henkilön hatun koko" << endl;
        cin >> hKoko;
        TIEDOT[kohta].etunimi = eNimi;
        TIEDOT[kohta].koulumatka = kMatka;
        TIEDOT[kohta].hattukoko = hKoko;
        if (kohta == *lkm - 1) { taynna = true; }
    }

    else if (taynna) { cout << endl << "Taulukko täynnä!" << endl; }
}

void PoistaHenkilo(tietue TIEDOT[]) {
	string nimi;
	string vastaus;
	cout << "Syötä henkilön etunimi jonka tiedot haluat poistaa" << endl;
    cin >> nimi;

    for (int a = 0; a < taulunKoko; a++) {
        if (TIEDOT[a].etunimi == nimi) {
            cout << endl << "Löytyi henkilö: " << TIEDOT[a].etunimi << " " << TIEDOT[a].koulumatka <<
            " " << TIEDOT[a].hattukoko << endl;
			cout << "Haluatko poistaa henkilön tiedot? k/e" << endl;
			cin >> vastaus;
			
			if (vastaus == "k") {
				for (int b = a; b < taulunKoko - 1; b++) {
					TIEDOT[b].etunimi = TIEDOT[b+1].etunimi;
					TIEDOT[b].koulumatka = TIEDOT[b+1].koulumatka;
					TIEDOT[b].hattukoko = TIEDOT[b+1].hattukoko;
				}
			 }
			
		else if (vastaus == "e") break;
        
		break;
        }

        if (a == taulunKoko - 1 && TIEDOT[a].etunimi != nimi) {
            cout << endl << "Ei löytynyt henkilöä: " << nimi << endl;
            break;
        }
    }
}

void TallennaTiedostoon(string tiedosto,tietue tietueTaulu[]) {
	ofstream ofilu(tiedosto);
	if (ofilu.is_open())
	{	
		for (int a = 0; a < taulunKoko; a++) {
			ofilu << tietueTaulu[a].etunimi << " " << tietueTaulu[a].koulumatka
			      << " " << tietueTaulu[a].hattukoko << endl;
		}
		ofilu.close();
	}
	else cout << "Ei voitu avata tiedostoa";
}

void LueTiedostosta(string tiedosto,tietue tietueTaulu[]) {
	string rivi;
	ifstream ifilu (tiedosto);
	if (ifilu.is_open())
	{
		while (getline (ifilu,rivi)) {
			cout << rivi << endl;
		}
		ifilu.close();
	}
	else cout << "Ei voitu avata tiedostoa"; 
}