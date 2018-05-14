#ifndef FEL_H
#define FEL_H

#include "Gomb.h"


class Fel: public Gomb
{
    public:
        Fel(int, int);
        virtual ~Fel();
        virtual void rajzol() override;
        virtual bool aktivalas();
        virtual void inaktivalas();
        virtual void esemeny(genv::event ev);
    protected:
    private:
        bool aktiv = false;
};

#endif // FEL_H
