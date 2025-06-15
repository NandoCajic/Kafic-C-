#include "Voditelj.h"
#include <iostream>

void Voditelj::pregledajPromet(const DnevniPromet& promet) const {
    std::cout << "Dnevni Promet:\n";
    promet.prikaziPromet();
}
