#ifndef GOST_H
#define GOST_H

#include <string>
#include "Cijenik.h"

class Gost {
private:
    std::string ime;

public:
    Gost(const std::string& i);
    
    std::string getIme() const;
    void setIme(const std::string& novoIme);

    void naruciPice(Cijenik& cijenik, const std::string& naziv);
};

#endif
