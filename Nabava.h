#ifndef NABAVA_H
#define NABAVA_H

#include <string>
#include "Skladiste.h"

class Nabava {
public:
    void naruciArtikl(Skladiste& skladiste, const std::string& artikl) const;
};

#endif
