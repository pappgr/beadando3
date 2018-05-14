#ifndef HAJO_H
#define HAJO_H

#include "Widget.h"

class Hajo: public Widget
{
    public:
        Hajo(int, int, int, int, int, int);
        int r,g,b,db;
        virtual ~Hajo();
        int xmeret();
        int ymeret();
        virtual void rajzol() override;
    protected:
    private:
        const int pxmeret = 20;
        const int pymeret = 20;
};


#endif

