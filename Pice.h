#ifndef PICE_H
#define PICE_H

#include <string>

class Pice {
private:
    std::string naziv;
    double cijena;

public:
    Pice(const std::string& n, double c);

    std::string getNaziv() const;
    void setNaziv(const std::string& n);

    double getCijena() const;
    void setCijena(double c);
};

#endif
