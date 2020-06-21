#include "Jatek.hpp"

    void Jatek::malom_ellenorzes(Jatekos& j){
        bool lepjen_ki;
        bool volt;
        do {
            lepjen_ki = true;
            try{
                volt = t->voltmalom();
                if (volt){
                    t->levesz(j);
                    t->malmok();
                    getmasik(&j)--;
                }
            }
            catch(std::invalid_argument e1){
                if (typeid(j) == typeid(Emberi_Jatekos))
                    std::cout << std::endl << e1.what() << std::endl;
                lepjen_ki = false;
            }
            catch(std::length_error e2){
                if (typeid(j) == typeid(Emberi_Jatekos))
                    std::cout << std::endl << e2.what() << std::endl;
                lepjen_ki = false;
            }
            catch(std::logic_error e3){
                if (typeid(j) == typeid(Emberi_Jatekos))
                    std::cout << std::endl << e3.what() << std::endl;
                lepjen_ki = false;
            }
            catch(std::range_error e){
                if (typeid(j) == typeid(Emberi_Jatekos))
                    std::cout << std::endl << e.what() << std::endl;
                lepjen_ki = false;
            }
        } while(!lepjen_ki);

    }

    void Jatek::elso_fazis_lepes(Jatekos& j){
        bool lepjen_ki;
        do {
            lepjen_ki = true;
            try{
                t->Lep(j.lepes(*t), j);
            }
            catch(std::invalid_argument e1){
                if (typeid(j) == typeid(Emberi_Jatekos))
                    std::cout << std::endl << e1.what() << std::endl;
                lepjen_ki = false;
            }
            catch(std::logic_error e2){
                if (typeid(j) == typeid(Emberi_Jatekos))
                    std::cout << std::endl << e2.what() << std::endl;
                lepjen_ki = false;
            }
            catch(std::range_error e){
                if (typeid(j) == typeid(Emberi_Jatekos))
                    std::cout << std::endl << e.what() << std::endl;
                lepjen_ki = false;
            }
        } while(!lepjen_ki);
        t->malmok();
        std::cout << *t;
        //t.malomkiir();
        malom_ellenorzes(j);
        std::cout << *t;
        //t.malomkiir();
    }

    void Jatek::masodik_fazis_lepes(Jatekos& j){
        bool lepjen_ki;
        do {
            lepjen_ki = true;
            try{
                t->Mozog(j.mozgas(*t), j);
            }
            catch(std::invalid_argument e1){
                if (typeid(j) == typeid(Emberi_Jatekos))
                    std::cout << std::endl << e1.what() << std::endl;
                lepjen_ki = false;
            }
            catch(std::domain_error e2){
                if (typeid(j) == typeid(Emberi_Jatekos))
                    std::cout << std::endl << e2.what() << std::endl;
                lepjen_ki = false;
            }
            catch(std::length_error e3){
                if (typeid(j) == typeid(Emberi_Jatekos))
                    std::cout << std::endl << e3.what() << std::endl;
                lepjen_ki = false;
            }
            catch(std::out_of_range e4){
                if (typeid(j) == typeid(Emberi_Jatekos))
                    std::cout << std::endl << e4.what() << std::endl;
                lepjen_ki = false;
            }
            catch(std::range_error e5){
                if (typeid(j) == typeid(Emberi_Jatekos))
                    std::cout << std::endl << e5.what() << std::endl;
                lepjen_ki = false;
            }
            } while(!lepjen_ki);
        t->malmok();
        std::cout << *t;
        malom_ellenorzes(j);
        std::cout << *t;
    }

    Jatek::Jatek(Jatekos *j1, Jatekos *j2, Tabla *t): j1(j1), j2(j2), t(t){}

    Jatekos& Jatek::getmasik(Jatekos * const j) const {
        if (&j == &j1)
            return *j2;
        return *j1;
    }

    void Jatek::elso_fazis(){
        std::cout << *t;
        for (size_t i = 0; i < 9; i++){
            std::cout << "Ennyi babut tudsz meg letenni: " << 9-i << std::endl;
            elso_fazis_lepes(*j1);
            (*j1)++;
            std::cout << "Ennyi babut tudsz meg letenni: " << 9-i << std::endl;
            elso_fazis_lepes(*j2);
            (*j2)++;
        }
    }
    void Jatek::masodik_fazis(){
        std::cout << *t;
        while(j1->getbabuk() >= 3 && j2->getbabuk() >= 3){
            std::cout << "Babuid szama: "<< j1->getbabuk() << std::endl;
            masodik_fazis_lepes(*j1);
            if (j1->getbabuk() <= 3 && j2->getbabuk() <= 3)
                break;
            std::cout << "Babuid szama: "<< j2->getbabuk() << std::endl;
            masodik_fazis_lepes(*j2);
        }
        std::cout << "A jatek veget ert!" << std::endl;
    }

