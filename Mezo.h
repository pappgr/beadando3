#ifndef MEZO_H
#define MEZO_H

#include "Widget.h"

class Mezo: public Widget
{
    public:
        Mezo(int, int);
        virtual ~Mezo();
        int xmeret();
        int ymeret();
        virtual void rajzol() override;
        virtual bool rajtavan(int evpx,int evpy);
        virtual bool aktivalas();
        virtual void inaktivalas();
        virtual void esemeny(genv::event ev);
    protected:
    private:
        const int pxmeret = 20;
        const int pymeret = 20;
        bool aktiv = false;
};


#endif
