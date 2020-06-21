#include "Hely.hpp"

Poz::Poz(std::string s) {
    sor = toupper(s[0]);
    oszlop = s[1] - '0';
}
Poz::Poz() {};

bool Poz::operator==(Poz p){
    return (sor == p.sor && oszlop == p.oszlop);
}

bool Poz::operator!=(std::string s){
    Poz tmp = s;
    return !(tmp == *this);
}

bool Poz::operator==(std::string s){
    Poz tmp = s;
    return tmp == *this;
}


Vonal::operator int() const {
    return hely;
}
bool Vonal::operator==(int i){
    return i == hely;
}


Hely::Hely(Vonal v1, Vonal v2): c(' '), v1(v1), v2(v2), elozo_malomban(false) , malomban(false) {}
Hely::Hely(): elozo_malomban(false), malomban(false) {}
char& Hely::getchar() {
    return c;
}
char Hely::getchar() const {
    return c;
}
Vonal Hely::getvonal1() const {
    return v1;
}
Vonal Hely::getvonal2() const {
    return v2;
}
char Hely::getmalombanc() const {
    if (malomban)
        return 'T';
    return 'F';
}

std::ostream& operator<<(std::ostream& os, Hely const h){
    return os << h.getchar();
}

