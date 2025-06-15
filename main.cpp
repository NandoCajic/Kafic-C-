#include <iostream>
#include <limits>
#include <vector>
#include "Gost.h"
#include "Konobar.h"
#include "Sanker.h"
#include "Voditelj.h"
#include "Sef.h"
#include "Pice.h"
#include "Cijenik.h"
#include "Nabava.h"
#include "Skladiste.h"
#include "DnevniPromet.h"

using namespace std;

int main() {
    Cijenik cijenik;
    cout << "\nDobrodosli u Malu Kafanu!\n";    	
	cout << "===========================\n";
	cout << "Neposluzujemo studente :P!\n";
	cout << "===========================\n";
    vector<Konobar> konobari = {
        Konobar("Nando", "Cajic", 28),
        Konobar("Vanda", "Jakic", 32),
        Konobar("Filip", "Laus", 25)
    };

   
    cout << "Odaberite konobara za ovu smjenu:\n";
    cout << "===========================\n";
    for (size_t i = 0; i < konobari.size(); ++i) {
        cout << i + 1 << ") ";
        konobari[i].prikaziPodatke();
    }

    int odabirKonobara;
    do {
    	cout << "===========================\n";
        cout << "Unesite broj konobara: ";
        cin >> odabirKonobara;
    } while (odabirKonobara < 1 || odabirKonobara > (int)konobari.size());

    Konobar aktivniKonobar = konobari[odabirKonobara - 1];

   
    cijenik.dodajPice("Kava", 1.5);
    cijenik.dodajPice("Kava s mlikom", 1.7);
    cijenik.dodajPice("Bila kava", 1.8);
    cijenik.dodajPice("Caj", 1.7);
    cijenik.dodajPice("Caj s ljubavlju", 200);
    cijenik.dodajPice("Coca Cola", 2.4);
    cijenik.dodajPice("Pipi", 2.2);
    cijenik.dodajPice("Sprite", 2.3);
    cijenik.dodajPice("Fanta", 2.4);
    cijenik.dodajPice("Ice Tea", 2.4);
    cijenik.dodajPice("Pivo Karlovacko 0,5", 3.5);
    cijenik.dodajPice("Pivo Toceno Karlovacko 0,5", 3);
    cijenik.dodajPice("Pivo Toceno Karlovacko 0,3", 2.5);
    cijenik.dodajPice("Pivo Toceno Paulaner weisbier 0,3", 4);
    cijenik.dodajPice("Pivo Toceno Paulaner weisbier 0,5", 4.5);
    cijenik.dodajPice("Pivo Paulaner weisbier 0,3", 5);
    cijenik.dodajPice("Pivo Paulaner weisbier 0,5", 5.5);
    cijenik.dodajPice("Orahovac", 1.5);    
    cijenik.dodajPice("Travarica", 1.5);
    cijenik.dodajPice("Pelinkovac", 1.5);    
    cijenik.dodajPice("Zutuja", 1.5);    
    cijenik.dodajPice("Vinjak", 1.5);

    Skladiste skladiste;


    for (const auto& pice : cijenik.getPica()) {
        skladiste.dodajZalihe(pice.getNaziv(), 10);
    }

    Nabava nabava;
    DnevniPromet promet;

    Sanker sanker;
    Voditelj voditelj;
    Sef sef;

    bool programAktivan = true;
    while (programAktivan) {
    	cout << "===========================\n";
        cout << "\nDobrodosli u Malu Kafanu!\n";    
        cout << "===========================\n";
		cout << "Neposluzujemo studente :P!\n";
		cout << "===========================\n";
        cout << "Jeste li:\n1) Gost\n2) Radnik\n0) Izlaz\n===========================\nOdabir: ";
        int uloga;
        cin >> uloga;

        if (uloga == 1) { 
            cout << "Unesite ime gosta: ";
            string ime;
            cin >> ime;
            Gost gost(ime);

            bool narucivanje = true;
            bool prikaziCijenik = true;

            while (narucivanje) {
                if (prikaziCijenik) {
                    cout << "\nCijenik:\n";
                    cout << "===========================\n";
                    cijenik.prikaziCijenik();
                }
  				cout << "===========================\n";
                cout << "Odaberite pice za naruciti (0 za izlaz): ";
              
                int izbor;
                cin >> izbor;

                if (izbor == 0) {
                    narucivanje = false;
                } else if (izbor > 0 && izbor <= (int)cijenik.getPica().size()) {
                    auto& pice = cijenik.getPica()[izbor - 1];

                    if (skladiste.smanjiZalihe(pice.getNaziv())) {
                        gost.naruciPice(cijenik, pice.getNaziv());
                        sanker.pripremiPice(pice.getNaziv());
                        aktivniKonobar.posluzi(gost, pice.getNaziv());
                        promet.dodajPromet(pice.getCijena());
                    } else {
                        cout << "Nazalost, " << pice.getNaziv() << " nije dostupno na skladistu.\n";
                    }
					cout << "===========================\n";
                    cout << "Zelite li jos nesto naruciti? (d/n): ";
                    char odgovor;
                    cin >> odgovor;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    if (odgovor == 'n' || odgovor == 'N') {
                        narucivanje = false;
                    } else {
                        prikaziCijenik = false; 
                    }
                } else {
                    cout << "Neispravan odabir.\n";
                }
            }

        } else if (uloga == 2) { 
            bool radnikAktivan = true;
            while (radnikAktivan) {
                cout << "\nRadnicki meni:\n";
                cout << "1) Provjeri zalihe (sef)\n";
                cout << "2) Pregledaj dnevni promet (voditelj)\n";
                cout << "3) Naruci artikl (nabava)\n";
                cout << "0) Izlaz\n";
                cout << "Odabir: ";
                int odabir;
                cin >> odabir;

                switch (odabir) {
                    case 1:
                        sef.provjeriZalihe(skladiste);
                        break;
                    case 2:
                        voditelj.pregledajPromet(promet);
                        break;
                    case 3: {
                        cout << "Unesite naziv artikla za nabavu: ";
                        string artikl;
                        cin >> artikl;
                        cout << "Unesite kolicinu: ";
                        int kolicina;
                        cin >> kolicina;

                        for (int i = 0; i < kolicina; ++i) {
                            nabava.naruciArtikl(skladiste, artikl);
                        }
                        break;
                    }
                    case 0:
                        radnikAktivan = false;
                        break;
                    default:
                        cout << "Neispravan odabir.\n";
                }
            }

        } else if (uloga == 0) {
            cout << "Izlaz iz programa.\n";
            programAktivan = false;
        } else {
            cout << "Neispravan unos uloge.\n";
        }
    }

    cout << "Hvala na posjeti!\n";
    return 0;
}
