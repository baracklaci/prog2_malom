#ifndef HELY
#define HELY
#include <cctype>
#include <exception>
#include <cstdlib>
#include <string>
#include <iostream>
#include "SzebiVektor.hpp"

enum vonalak{va, vb, vc, vd2, vd6, ve, vf, vg, v1, v2, v3, v4b, v4f, v5, v6, v7};

struct Poz{
    char sor;
    int oszlop;
    Poz();
    Poz(std::string s);
    bool operator==(Poz p);
    bool operator!=(std::string s);
    bool operator==(std::string s);
};

class Vonal{
    int hely;
public:
    Vonal(int i): hely(i) {}
    Vonal(){}
    operator int() const;
    bool operator==(int i);
};


class Hely{
    char c;
    Vonal v1, v2;
public:
    bool elozo_malomban;
    bool malomban;
    Hely(Vonal v1, Vonal v2);
    Hely();
    char& getchar();
    char getchar() const;
    Vonal getvonal1() const;
    Vonal getvonal2() const;
    char getmalombanc() const;
};

std::ostream& operator<<(std::ostream& os, Hely const h);

#endif
