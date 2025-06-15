#include "Skladiste.h"
#include <iostream>

void Skladiste::dodajZalihe(const std::string& artikl, int kolicina) {
    zalihe[artikl] += kolicina;
}

bool Skladiste::smanjiZalihe(const std::string& artikl) {
    auto it = zalihe.find(artikl);
    if (it != zalihe.end() && it->second > 0) {
        it->second--;
        return true;
    }
    return false;
}

int Skladiste::getStanje(const std::string& artikl) const {
    auto it = zalihe.find(artikl);
    return (it != zalihe.end()) ? it->second : 0;
}

void Skladiste::prikaziZalihe() const {
    std::cout << "\n--- Zalihe ---\n";
    for (const auto& par : zalihe) {
        std::cout << par.first << ": " << par.second << " kom\n";
    }
}
