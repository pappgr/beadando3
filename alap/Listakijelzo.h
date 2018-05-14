#ifndef LISTAKIJELZO_H
#define LISTAKIJELZO_H

#include "vector"
#include "Widget.h"
using namespace std;

class Listakijelzo: public Widget
{
    public:
        Listakijelzo(int, int);
        virtual ~Listakijelzo();
        virtual void rajzolszoveg();
        virtual void szinez(int);
        virtual void rajzolszinez();
        virtual void rajzolegyeb();
        virtual void rajzol() override;
        virtual void magassag(int);
        virtual void vectorBE(vector<string>);
        virtual void eltolasBE(int);
        virtual int eltolasKI();
        virtual void valasztasBE(int);
        virtual int valasztasKI();
        virtual void esemeny(genv::event ev);
    protected:
    private:
        const int pxmeret = 160;
        const int pymeret = 168;
        int szorzo = 1, i = 0, kivalasztott = 0;
        string elso = "elso",masodik = "masodik",harmadik="harmadik",negyedik="negyedik";
        vector<string> lista;
};

#endif // LISTAKIJELZO_H
