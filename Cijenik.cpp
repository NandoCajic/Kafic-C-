#include "Cijenik.h"
#include <iostream>

void Cijenik::dodajPice(const std::string& naziv, double cijena) {
    pica.emplace_back(naziv, cijena);
}


void Cijenik::prikaziCijenik() const {
    for (size_t i = 0; i < pica.size(); ++i) {
        std::cout << (i + 1) << ") " << pica[i].getNaziv() << " - " << pica[i].getCijena() << " EUR\n";
    }
}

const std::vector<Pice>& Cijenik::getPica() const {
    return pica;
}
