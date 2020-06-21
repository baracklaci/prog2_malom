#include "Jatekos.hpp"
#include "random.hpp"

Jatekos::Jatekos(char c): c(c), babuk(0) {}
char Jatekos::getchar() const {
    return c;
}
void Jatekos::operator++(int ){
    babuk++;
}
void Jatekos::operator--(int ){
    babuk--;
}
int Jatekos::getbabuk(){
    return babuk;
}
Jatekos::~Jatekos() {}


Emberi_Jatekos::Emberi_Jatekos(char c): Jatekos(c) {}
Poz Emberi_Jatekos::lepes(Tabla& t) const {
    std::string s;
    std::cout << "Add meg hova szeretnel lepni! (" << (char)this->getchar() << ")" << std::endl;
    std::cin >> s;
    if (s.size() < 2)
        throw std::range_error("Rossz szoveget adtal meg!");
    Poz p(s);
    return p;
}
Poz Emberi_Jatekos::levesz(Tabla& t) const {
    std::string s;
    std::cout << "Melyik babut szeretned levenni? (" << (char)this->getchar() << ")" << std::endl;
    std::cin >> s;
    if (s.size() < 2)
        throw std::range_error("Rossz szoveget adtal meg!");
    Poz p(s);
    return p;
}
SzebiVektor<Poz> Emberi_Jatekos::mozgas(Tabla& t) const {
    std::string s;
    std::cout << "Mivel, hova szeretnel lepni? (" << (char)this->getchar() << ")" << std::endl;
    //std::cin.ignore(99999, '\n');
    getline(std::cin, s);
    //scanf("%[^\n]", s);
    //std::cin.ignore(99999, '\n');
    //std::cin.get();
    SzebiVektor<Poz> p;
    if (s.size() < 4)
        throw std::range_error("Rossz szoveget adtal meg!");
    try{
        p.pushback(h1_valid(s));
        p.pushback(h2_valid(s));
    }
    catch(std::length_error e){
        throw e;
    }
    return p;
}

Poz Emberi_Jatekos::h1_valid(std::string s) const {
    Poz elso_hely = s.substr(0, 2);
    return elso_hely;
}
Poz Emberi_Jatekos::h2_valid(std::string s) const {
    int idx = 2;
    while(!isalpha(s[idx]) && idx < 20) {             ///elmegy az elso betuig, amit talal
            idx++;
    }
    if (idx >= 20)
        throw std::length_error("Rossz szoveget adtal meg!");
    Poz masodik_hely = s.substr(idx, 2);
    return masodik_hely;
    }

Poz Gepi_Jatekos::random_poz() const {
    int x = backoff_time.rand();
    switch (x){
        case 0:
            return Poz("A1");
        case 1:
            return Poz("A4");
        case 2:
            return Poz("A7");
        case 3:
            return Poz("B2");
        case 4:
            return Poz("B4");
        case 5:
            return Poz("B7");
        case 6:
            return Poz("C3");
        case 7:
            return Poz("C4");
        case 8:
            return Poz("C5");
        case 9:
            return Poz("D1");
        case 10:
            return Poz("D2");
        case 11:
            return Poz("D3");
        case 12:
            return Poz("D5");
        case 13:
            return Poz("D6");
        case 14:
            return Poz("D7");
        case 15:
            return Poz("E3");
        case 16:
            return Poz("E4");
        case 17:
            return Poz("E5");
        case 18:
            return Poz("F2");
        case 19:
            return Poz("F4");
        case 20:
            return Poz("F6");
        case 21:
            return Poz("G1");
        case 22:
            return Poz("G4");
    }
    return Poz("G7");
}

Gepi_Jatekos::Gepi_Jatekos(char c): Jatekos(c) {}
Poz Gepi_Jatekos::lepes(Tabla& t) const {
    return random_poz();
}
Poz Gepi_Jatekos::levesz(Tabla& t) const {
    return random_poz();
}
SzebiVektor<Poz> Gepi_Jatekos::mozgas(Tabla& t) const {
    SzebiVektor<Poz> p;
    p.pushback(random_poz());
    p.pushback(random_poz());
    return  p;
}
