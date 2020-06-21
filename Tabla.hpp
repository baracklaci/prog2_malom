#ifndef TABLA
#define TABLA
#include <cctype>
#include <exception>
#include <cstdlib>
#include <cstring>
#include "Jatekos.hpp"



class Tabla{
    SzebiVektor<Hely> helyek;
public:
    Tabla();

    Hely& operator[](size_t n);

    Hely operator[](size_t n) const;

    bool valid_hely(Poz p) const;

    Hely& gethely(Poz p);

    void Lep(Poz p,const Jatekos& j);

    Poz h1_valid(Poz p, const Jatekos& j);
    Poz h2_valid(Poz p, const Jatekos& j);

    bool mellette_van(Poz p1, Poz p2) const;

    bool h1_valid(Poz hely, Jatekos& j);

    bool h2_valid(Poz hely, Jatekos& j);

    void Mozog(SzebiVektor<Poz> p, Jatekos& j);

    void malmok();

    bool voltmalom() const;

    void levesz(const Jatekos& j);

    void malomkiir() const;

};

std::ostream& operator<<(std::ostream& os, const Tabla& t);

#endif
