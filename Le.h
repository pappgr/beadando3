#ifndef LE_H
#define LE_H

#include "Gomb.h"


class Le: public Gomb
{
    public:
        Le(int, int);
        virtual ~Le();
        virtual void rajzol() override;
        virtual bool aktivalas();
        virtual void inaktivalas();
        virtual void esemeny(genv::event ev);
    protected:
    private:
        bool aktiv = false;
};

#endif // LE_H
