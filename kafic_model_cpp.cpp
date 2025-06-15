// main.cpp
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

int main() {
    Cijenik cijenik;
    cijenik.dodajPice("Kava", 1.5);
    cijenik.dodajPice("Pivo", 2.5);

    Skladiste skladiste;
    Nabava nabava;
    DnevniPromet promet;

    Gost gost("Ivan");
    Konobar konobar("Marko");
    Sanker sanker;
    Voditelj voditelj;
    Sef sef;

    cijenik.prikaziCijenik();
    gost.naruciPice(cijenik, "Kava");
    sanker.pripremiPice("Kava");
    konobar.posluzi(gost, "Kava");
    promet.dodajPromet(1.5);

    nabava.naruciArtikl(skladiste, "Kava zrna");
    sef.provjeriZalihe(skladiste);
    voditelj.pregledajPromet(promet);

    return 0;
}
