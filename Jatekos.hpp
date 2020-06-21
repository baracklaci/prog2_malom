#ifndef JATEKOS
#define JATEKOS
#include <iostream>
#include "Hely.hpp"



class Tabla;

class Jatekos{
    const char c;
    int babuk;
public:
    Jatekos(char c);
    char getchar() const;
    void operator++(int );
    void operator--(int );
    int getbabuk();
    virtual Poz lepes(Tabla& t) const = 0;
    virtual Poz levesz(Tabla& t) const = 0;
    virtual SzebiVektor<Poz> mozgas(Tabla& t) const = 0;
    virtual ~Jatekos();

};

class Emberi_Jatekos: public Jatekos {
public:
    Emberi_Jatekos(char c);
    Poz lepes(Tabla& t) const;
    Poz levesz(Tabla& t) const;
    SzebiVektor<Poz> mozgas(Tabla& t) const;
    Poz h1_valid(std::string s) const;
    Poz h2_valid(std::string s) const;
};

class Gepi_Jatekos: public Jatekos {
    Poz random_poz() const;
public:
    Gepi_Jatekos(char c);
    Poz lepes(Tabla& t)const;
    Poz levesz(Tabla& t)const;
    SzebiVektor<Poz> mozgas(Tabla& t)const;
};

#endif
