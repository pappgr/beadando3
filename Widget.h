#ifndef WIDGET_H
#define WIDGET_H
#include "graphics.hpp"

class Widget{
    public:
        Widget(int x, int y);
        virtual ~Widget();
        int x();
        int y();
        virtual void rajzol()=0;
        virtual void esemeny(genv::event ev)=0;
    protected:
    private:
        int px, py;
};

#endif
