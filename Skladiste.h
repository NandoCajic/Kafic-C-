#ifndef SKLADISTE_H
#define SKLADISTE_H

#include <map>
#include <string>

class Skladiste {
private:
    std::map<std::string, int> zalihe;

public:
    void dodajZalihe(const std::string& artikl, int kolicina);
    bool smanjiZalihe(const std::string& artikl);
    int getStanje(const std::string& artikl) const;
    void prikaziZalihe() const;
};

#endif
