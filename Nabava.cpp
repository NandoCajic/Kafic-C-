#include "Nabava.h"
#include <iostream>

void Nabava::naruciArtikl(Skladiste& skladiste, const std::string& artikl) const {
    std::cout << "Nabava: narucen artikl - " << artikl << "\n";
    skladiste.dodajZalihe(artikl, 1);
}
