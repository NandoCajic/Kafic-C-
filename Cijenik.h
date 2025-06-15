#ifndef CIJENIK_H
#define CIJENIK_H

#include <vector>
#include "Pice.h"

class Cijenik {
private:
    std::vector<Pice> pica;

public:
    void dodajPice(const std::string& naziv, double cijena);
    void prikaziCijenik() const;

    const std::vector<Pice>& getPica() const;
};

#endif
