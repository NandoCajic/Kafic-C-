#include "Sef.h"
#include <iostream>

void Sef::provjeriZalihe(const Skladiste& skladiste) const {
    std::cout << "Provjerava zalihe:\n";
    skladiste.prikaziZalihe();
}
