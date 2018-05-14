#ifndef SZAMKIJELZO_H
#define SZAMKIJELZO_H

#include "Widget.h"


class Szamkijelzo: public Widget
{
    public:
        Szamkijelzo(int, int);
        virtual ~Szamkijelzo();
        int szam();
        std::string tostring(int);
        virtual void rajzol() override;
        virtual void esemeny(genv::event ev);
        int SzamKI();
        void SzamBE(int);
    protected:
    private:
        const int kxmeret = 100;
        const int kymeret = 100;
};

#endif
