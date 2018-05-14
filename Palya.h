#ifndef PALYA_H_INCLUDED
#define PALYA_H_INCLUDED

#include "graphics.hpp"
#include "Widget.h"
#include "Mezo.h"


class Palya
{

public:
    Palya(int _x, int _y);
    virtual ~Palya();

    void event_loop();
    void vektor();


protected:
    int x, y;
};

#endif
