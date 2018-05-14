#ifndef GORGETO_H
#define GORGETO_H

#include "Widget.h"


class Gorgeto: public Widget
{
    public:
        Gorgeto(int, int);
        virtual ~Gorgeto();
        virtual void rajzol() override;
        virtual void esemeny(genv::event ev);
        virtual void elmozdul(int,int);
        virtual void meret(int);
    protected:
    private:
        const int pxmeret = 20;
        int pymeret = 124;
        int eltolas = 0;
};

#endif // GORGETO_H
