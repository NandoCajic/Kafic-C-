#include "Konobar.h"
#include <iostream>

Konobar::Konobar(const std::string& i, const std::string& p, int g)
    : ime(i), prezime(p), godine(g) {}

void Konobar::posluzi(const Gost& gost, const std::string& pice) const {
    std::cout << "Konobar " << ime << " " << prezime << " posluzuje "
              << gost.getIme() << " s: " << pice << "\n";
}

std::string Konobar::getIme() const {
    return ime;
}

std::string Konobar::getPrezime() const {
    return prezime;
}

int Konobar::getGodine() const {
    return godine;
}

void Konobar::prikaziPodatke() const {
    std::cout << ime << " " << prezime << ", " << godine << " god.\n";
}
