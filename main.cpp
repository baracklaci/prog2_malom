#include <iostream>
#include <stdio.h>
#include <string>

#include "Jatek.hpp"

std::istream& getline(std::istream& is, std::string& str) {
    std::getline(is, str);
    if (str.size() && *str.rbegin() == '\r')
        str.erase(str.size()-1);
    return is;
  }

int main()
{
    setbuf(stdout, 0);
    Emberi_Jatekos j1('#');
    Jatekos* j2;
    std::string s;
    int x;
    bool kilep = true;
    do {
    try{
        std::cout << "Ember ellen szeretnel jatszani (1) vagy gep ellen (2)?" << std::endl;
        getline(std::cin, s);
        std::cin.clear();
        x = s[0] - '0';
        if (x == 1){
            j2 = new Emberi_Jatekos('@');
            kilep = true;
        }
        else if (x == 2){
            j2 = new Gepi_Jatekos('@');
            kilep = true;
        }
        else{
            kilep = false;
            throw std::invalid_argument("1-et vagy 2-t adj meg pls!");
        }
    }
    catch(std::invalid_argument e){
        std::cout << e.what() << std::endl;
    }
    }while(!kilep);
    Tabla t;
    Jatek j(&j1, j2, &t);
    j.elso_fazis();
    j.masodik_fazis();
    delete j2;
    return 0;
}
