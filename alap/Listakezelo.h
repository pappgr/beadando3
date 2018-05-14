#ifndef LISTAKEZELO_H
#define LISTAKEZELO_H

#include "Widget.h"
#include "Fel.h"
#include "Le.h"
#include "Listakijelzo.h"
#include "ListaGomb.h"
#include "Gorgeto.h"
#include <vector>

using namespace std;

class Listakezelo: public Widget
{
    public:
        Listakezelo(int,int,vector<string>);
        virtual ~Listakezelo();
        virtual void elemhozzaad(string);
        virtual void fajlbair();
        virtual void rajzol() override;
        virtual void kijelzokalibrator();
        virtual void valasztaskalibrator();
        virtual void esemeny(genv::event ev);
    protected:
    private:
        bool egyszerfut =true;
        Fel f;
        Le l;
        Listakijelzo listaj;
        ListaGomb listag;
        Gorgeto gor;
        vector<string> v;
        int eltol, kivalasztott;
};

#endif // LISTAKEZELO_H
