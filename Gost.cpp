#include "Gost.h"
#include <iostream>

Gost::Gost(const std::string& i) : ime(i) {}

std::string Gost::getIme() const {
    return ime;
}

void Gost::setIme(const std::string& novoIme) {
    ime = novoIme;
}

void Gost::naruciPice(Cijenik& cijenik, const std::string& naziv) {
    for (const auto& p : cijenik.getPica()) {
        if (p.getNaziv() == naziv) {
            std::cout << ime << " je narucio/la " << p.getNaziv() << " za " << p.getCijena() << " EUR\n";
            return;
        }
    }
    std::cout << "Pice nije dostupno.\n";
}
