#include "Tabla.hpp"

    Tabla::Tabla(){
        helyek.pushback(Hely(1, 9));
        helyek.pushback(Hely(4, 9));
        helyek.pushback(Hely(8, 9));
        helyek.pushback(Hely(2, 10));
        helyek.pushback(Hely(4, 10));
        helyek.pushback(Hely(7, 10));
        helyek.pushback(Hely(3, 11));
        helyek.pushback(Hely(4, 11));
        helyek.pushback(Hely(6, 11));
        helyek.pushback(Hely(1, 12));
        helyek.pushback(Hely(2, 12));
        helyek.pushback(Hely(3, 12));
        helyek.pushback(Hely(6, 13));
        helyek.pushback(Hely(7, 13));
        helyek.pushback(Hely(8, 13));
        helyek.pushback(Hely(3, 14));
        helyek.pushback(Hely(5, 14));
        helyek.pushback(Hely(6, 14));
        helyek.pushback(Hely(2, 15));
        helyek.pushback(Hely(5, 15));
        helyek.pushback(Hely(7, 15));
        helyek.pushback(Hely(1, 16));
        helyek.pushback(Hely(5, 16));
        helyek.pushback(Hely(8, 16));
    }

    Hely& Tabla::operator[](size_t n){
        return helyek[n];
    }

    Hely Tabla::operator[](size_t n) const {
        return helyek[n];
    }

    bool Tabla::valid_hely(Poz p) const {
        return (p == "A1" || p == "A4" || p == "A7" || p == "B2" || p == "B4" || p == "B6" || p == "C3" || p == "C4" || p == "C5" ||
            p == "D1" || p == "D2" || p == "D3" || p == "D5" || p == "D6" || p == "D7" || p == "E3" || p == "E4" || p == "E5" ||
            p == "F2" || p == "F4" || p == "F6" || p == "G1" || p == "G4" || p == "G7");
    }

    Hely& Tabla::gethely(Poz p) {
        if (!valid_hely(p))
            throw std::invalid_argument("Rossz szoveget adtal meg!");
        int betu = p.sor - 'A';
        int szam = p.oszlop-1;
        int oszlop;
        if (szam == 3){
            if (betu <= 2)
                return helyek[9 + betu];
            else
                return helyek[9 + betu -1];
        }
        if (szam <= 2){
            if (betu <= 2)
                oszlop = 0;
            else if (betu == 3)
                oszlop = 1;
            else if (betu >= 4)
                oszlop = 2;
        }
        if (szam >= 4){
            szam++;
            if (betu <= 2)
                oszlop = 0;
            else if (betu == 3)
                oszlop = 1;
            else if (betu >= 4)
                oszlop = 2;
        }
        return helyek[szam*3 + oszlop];
    }

    void Tabla::Lep(Poz p ,const Jatekos& j){
        if (!valid_hely(p))
            throw std::range_error("Rossz szoveget adtal meg!");
        if (gethely(p).getchar() != ' ')
            throw(std::logic_error("A mezo mar foglalt!"));
        gethely(p).getchar() = j.getchar();
    }

    bool Tabla::mellette_van(Poz h1, Poz h2) const {
        int h1szam = h1.oszlop;
        int h2szam = h2.oszlop;
        char h1betu = h1.sor;
        char h2betu = h2.sor;
        int kulonbseg;
        if (h1betu == h2betu){
            switch(h1betu){
                case 'A':
                case 'G':
                    kulonbseg = 3;
                    break;
                case 'B':
                case 'F':
                    kulonbseg = 2;
                    break;
                default:
                    kulonbseg = 1;
            }
            if (abs(h1szam - h2szam) == kulonbseg)
                return true;
        }
        if (h1szam == h2szam){
            switch(h1szam){
                case 1:
                case 7:
                    kulonbseg = 3;
                    break;
                case 2:
                case 6:
                    kulonbseg = 2;
                    break;
                default:
                    kulonbseg = 1;
            }
            if (abs(h1betu - h2betu) == kulonbseg)
                return true;
        }
        return false;
    }

    bool Tabla::h1_valid(Poz hely, Jatekos& j){
        char& h1 = gethely(hely).getchar();
        return h1 == j.getchar();
        //throw std::domain_error("Nem a sajat babudat akartad mozgatni!");
    }

    bool Tabla::h2_valid(Poz hely, Jatekos& j){
        char& h1 = gethely(hely).getchar();
        return (h1 == j.getchar() || h1 == ' ');
        //throw std::domain_error("Nem a sajat babudat akartad mozgatni!");
    }

    void Tabla::Mozog(SzebiVektor<Poz> p, Jatekos& j){
    Poz elso = p[0];
    if (!valid_hely(elso))
        throw std::length_error("Rossz szoveget adtal meg!");
    if (!h1_valid(elso, j))
        throw std::domain_error("Nem a sajat babudat akartad mozgatni!");
    Poz masodik = p[1];
    if (!valid_hely(masodik))
        throw std::length_error("Rossz szoveget adtal meg!");
    if (!h2_valid(masodik, j))
        throw std::domain_error("Rossz helyre akartal lepni!");
    if (j.getbabuk() == 3)
    {
        gethely(elso).getchar() = ' ';
        gethely(masodik).getchar() = j.getchar();
    }
    else if (mellette_van(elso, masodik))
    {
        gethely(elso).getchar() = ' ';
        gethely(masodik).getchar() = j.getchar();
    }
    else
        throw std::range_error("Nem a babu melletti pozicioba akartal lepni!");

    }

    void Tabla::malmok(){
        for (int i = 0; i < 24; i++){
            helyek[i].elozo_malomban=helyek[i].malomban;
        }
        for (int j = 0; j < 24; j++){
            helyek[j].malomban = false;
        }
        for (int i = 1; i <= 16; i++){   ///végigmegy a vonalakon
            int c[3];
            int idx = 0;
            for (int j = 0; j < 24; j++)
                if ((i == (helyek[j].getvonal1())) || (i == (helyek[j].getvonal2()))) ///kiválasztja a 3 helyet, ami a vonalon van
                    c[idx++] = j;
            if (helyek[c[0]].getchar() == helyek[c[1]].getchar() && helyek[c[1]].getchar() == helyek[c[2]].getchar() &&
                 helyek[c[0]].getchar() != ' ') ///ha a három helyen a karakter egyezik malom
                for (int j = 0; j < 3; j++)
                    helyek[c[j]].malomban = true;
        }
    }

    bool Tabla::voltmalom() const {
        for (int i = 0; i < 24; i++){
            if (helyek[i].elozo_malomban == false && helyek[i].malomban == true)
                return true;
        }
        return false;
    }

    void Tabla::levesz(const Jatekos& j){
    Poz p = j.levesz(*this);
    if (!valid_hely(p))
        throw std::range_error("Rossz szoveget adtal meg!");
    Hely& h = gethely(p);
    char& c = h.getchar();
    bool csakmalombanvanbabu = true;
    for (int i = 0; i < 24; i++)
    {
        if (helyek[i].getchar() != ' ' && helyek[i].getchar() != j.getchar() && !helyek[i].malomban)
        {
            csakmalombanvanbabu = false;
            break;
        }
    }
    if (h.malomban && c != j.getchar() && !csakmalombanvanbabu)
        throw std::length_error("A babu malomban van!");
    if (c != ' ' && c != j.getchar())
        c = ' ';
    else
        throw std::length_error("Rossz mezot valasztottal!");
}

    void Tabla::malomkiir() const {
        std::cout << "\n\n7  " << helyek[21].getmalombanc() << "---------------" << helyek[22].getmalombanc() <<"---------------" << helyek[23].getmalombanc() << std::endl;
        std::cout << "   |               |               |" << std::endl;
        std::cout << "6  |     " << helyek[18].getmalombanc() << "---------" << helyek[19].getmalombanc() << "---------" << helyek[20].getmalombanc() << "     |" << std::endl;
        std::cout << "   |     |         |         |     |" << std::endl;
        std::cout << "5  |     |    " << helyek[15].getmalombanc() << "----" << helyek[16].getmalombanc()<< "----" << helyek[17].getmalombanc() << "    |     |" << std::endl;
        std::cout << "   |     |    |         |    |     |" << std::endl;
        std::cout << "4  " << helyek[9].getmalombanc() << "-----" << helyek[10].getmalombanc() << "----" << helyek[11].getmalombanc() << "         " << helyek[12].getmalombanc() << "----" << helyek[13].getmalombanc() << "-----" << helyek[14].getmalombanc() << "" << std::endl;
        std::cout << "   |     |    |         |    |     |" << std::endl;
        std::cout << "3  |     |    " << helyek[6].getmalombanc() << "----" << helyek[7].getmalombanc() << "----" << helyek[8].getmalombanc() << "    |     |" << std::endl;
        std::cout << "   |     |         |         |     |" << std::endl;
        std::cout << "2  |     " << helyek[3].getmalombanc() << "---------" << helyek[4].getmalombanc() << "---------" << helyek[5].getmalombanc() << "     |" << std::endl;
        std::cout << "   |               |               |" << std::endl;
        std::cout << "1  " << helyek[0].getmalombanc() << "---------------" << helyek[1].getmalombanc() <<"---------------" << helyek[2].getmalombanc() << std::endl;
        std::cout << "   A     B    C    D    E    F     G" << std::endl;
    }

std::ostream& operator<<(std::ostream& os, const Tabla& t) {
        //system("cls");
        /*os << "7  " << t[21] << "---------------" << t[22] <<"---------------" << t[23] << std::endl;
        os << "   |               |               |" << std::endl;
        os << "6  |     " << t[18] << "---------" << t[19] << "---------" << t[20] << "     |" << std::endl;
        os << "   |     |         |         |     |" << std::endl;
        os << "5  |     |    " << t[15] << "----" << t[16] << "----" << t[17] << "    |     |" << std::endl;
        os << "   |     |    |         |    |     |" << std::endl;
        os << "4  " << t[9] << "-----" << t[10] << "----" << t[11] << "         " << t[12] << "----" << t[13] << "-----" << t[14] << "" << std::endl;
        os << "   |     |    |         |    |     |" << std::endl;
        os << "3  |     |    " << t[6] << "----" << t[7] << "----" << t[8] << "    |     |" << std::endl;
        os << "   |     |         |         |     |" << std::endl;
        os << "2  |     " << t[3] << "---------" << t[4] << "---------" << t[5] << "     |" << std::endl;
        os << "   |               |               |" << std::endl;
        os << "1  " << t[0] << "---------------" << t[1] <<"---------------" << t[2] << std::endl;
        os << "   A     B    C    D    E    F     G" << std::endl;*/
    return os;
}

