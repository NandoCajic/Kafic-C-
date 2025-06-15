#include "Pice.h"

Pice::Pice(const std::string& n, double c) : naziv(n), cijena(c) {}

std::string Pice::getNaziv() const {
    return naziv;
}

void Pice::setNaziv(const std::string& n) {
    naziv = n;
}

double Pice::getCijena() const {
    return cijena;
}

void Pice::setCijena(double c) {
    cijena = c;
}
