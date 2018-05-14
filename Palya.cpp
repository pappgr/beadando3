#include "Palya.h"
#include "Widget.h"
#include "vector"


using namespace genv;
using namespace std;

Palya::Palya(int _x, int _y)
{
    x=_y;
    y=_x;

    gout.open(_x, _y);

     vector<Mezo*>mezok;
    for (int i=0; i<100; i++)
    {
        mezok.push_back(new Mezo(i*Mezo::xmeret(),i*Mezo::ymeret()));
    }

}


Palya::~Palya(){}

void vektor()
{

}


void Palya::event_loop()
{
    event ev;


    while(gin>>ev && ev.keycode!=key_escape)
    {
        for (int i=0; i<100; i++)
        {
            mezok.[i]->esemeny(ev);
            mezok.[i]->rajzol();

    }
    }
}
