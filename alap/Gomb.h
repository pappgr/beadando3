#ifndef GOMB_H
#define GOMB_H

#include "Widget.h"


class Gomb: public Widget
{
    public:
        Gomb(int, int);
        virtual ~Gomb();
        int xmeret();
        int ymeret();
        virtual void rajzol() override;
        virtual bool rajtavan(int evpx,int evpy);
    protected:
    private:
        const int pxmeret = 20;
        const int pymeret = 20;
};

#endif // GOMB_H
