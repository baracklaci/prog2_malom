#ifndef JATEK
#define JATEK

#include <typeinfo>
#include "Tabla.hpp"

class Jatek{
    Jatekos  *j1, *j2;
    Tabla *t;
    void malom_ellenorzes(Jatekos& j);

    void elso_fazis_lepes(Jatekos& j);

    void masodik_fazis_lepes(Jatekos& j);

public:
    Jatek(Jatekos *j1, Jatekos *j2, Tabla *t);

    Jatekos& getmasik(Jatekos * const j) const;

    void elso_fazis();
    void masodik_fazis();
};


#endif
