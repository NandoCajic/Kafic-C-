#include "DnevniPromet.h"
#include <iostream>

DnevniPromet::DnevniPromet() : ukupno(0) {}

double DnevniPromet::getUkupno() const {
    return ukupno;
}

void DnevniPromet::dodajPromet(double iznos) {
    ukupno += iznos;
}

void DnevniPromet::prikaziPromet() const {
    std::cout << "Ukupni dnevni promet: " << ukupno << " EUR\n";
}
