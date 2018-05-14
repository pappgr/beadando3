#ifndef LISTAGOMB_H
#define LISTAGOMB_H

#include "Widget.h"


class ListaGomb:public Widget
{
    public:
        ListaGomb(int, int);
        virtual ~ListaGomb();
        virtual bool rajtavan(int, int);
        virtual bool sz1();
        virtual bool sz2();
        virtual bool sz3();
        virtual bool sz4();
        virtual void inaktivalas();
        virtual void rajzol() override;
        virtual void esemeny(genv::event ev);
    protected:
    private:
        const int pxmeret = 160;
        const int pymeret = 180;
        bool szektor1 = false, szektor2 = false, szektor3 = false, szektor4 = false;
};

#endif // LISTAGOMB_H
