#ifndef KONOBAR_H
#define KONOBAR_H

#include <string>
#include "Gost.h"

class Konobar {
private:
    std::string ime;
    std::string prezime;
    int godine;

public:
    Konobar(const std::string& ime, const std::string& prezime, int godine);

    void posluzi(const Gost& gost, const std::string& pice) const;

    std::string getIme() const;
    std::string getPrezime() const;
    int getGodine() const;
    void prikaziPodatke() const;
};

#endif
