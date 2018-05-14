#ifndef SZAMKEZELO_H
#define SZAMKEZELO_H

#include "Widget.h"
#include "Szamkijelzo.h"

class Szamkezelo: public Widget
{
    public:
        Szamkezelo(int,int,int,int,int);
        virtual ~Szamkezelo();
        virtual void fajlbair();
        virtual void rajzol() override;
        virtual void esemeny(genv::event ev);
    protected:
    private:
        Fel f;
        Le l;
        Szamkijelzo szamj;
        int maxi,mini,ertek;
        bool egyszeri = true;
};

#endif
