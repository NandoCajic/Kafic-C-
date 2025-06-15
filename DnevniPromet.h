#ifndef DNEVNIPROMET_H
#define DNEVNIPROMET_H

class DnevniPromet {
private:
    double ukupno;

public:
    DnevniPromet();

    double getUkupno() const;
    void dodajPromet(double iznos);
    void prikaziPromet() const;
};

#endif
