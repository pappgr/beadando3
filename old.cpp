#include "graphics.hpp"
#include "Szamkezelo.h"
#include "Listakezelo.h"
#include <vector>

using namespace genv;
using namespace std;

const int xkepernyo = 800;
const int ykepernyo = 600;


int main()
{
    gout.open(xkepernyo,ykepernyo);
    event ev;
    vector <string> lista1{"elem1","elem2","elem3","elem4","elem5","elem6","elem7","elem8","elem9","elem10"};
    vector <string> lista2{"elem_A","elem_B","elem_C","elem_D","elem_E","elem_F"};

    Listakezelo* lk1= new Listakezelo(500,100,lista1);
    Listakezelo* lk2= new Listakezelo(500,350,lista2);
    vector<Widget*> widgets;
    widgets.push_back(new Szamkezelo(100,150,100,96,1012));
    widgets.push_back(new Szamkezelo(100,250,1000,982,1020));
    widgets.push_back(lk2);
    widgets.push_back(lk1);

    lk1->elemhozzaad("szam_add");
    lk2->elemhozzaad("betu_add");

    while(gin >> ev && ev.keycode != key_escape) {
        for (Widget* w: widgets) {
            w->esemeny(ev);
            w->rajzol();
        }
        gout << refresh;
    }
    return 0;
}
