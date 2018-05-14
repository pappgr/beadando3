#include "Boxok.hpp"
#include "Menu.hpp"
#include "graphics.hpp"
#include "Textbox.hpp"
#include <vector>
#include <iostream>
#include <fstream>
using namespace genv;
using namespace std;

void Clear()
{
    gout << move_to(0,0) << color(0,0,0) << box(700,500);
}

void Kiiras(Widget* m)
{
    ofstream mentes("tarolas.txt");
    mentes << m->Konvertalas();
    mentes.close();
}

int main()
{
    gout.open(700,500);
    vector<Widget*> w;
    vector<string> s={"Anya","Apa","Te$ó","Hugi","Eszti","Patya"};
    vector<string> s2={"+36 30 1394163","+36 30 5579514","+36 30 2699475","+36 30 9448516","+36 30 6118497","+36 30 6969696"};
    Boxok * b1 = new Boxok(60,40,100,90,100,300);
    Boxok * b2 = new Boxok(60,150,100,90,-100,0);
    w.push_back(b2);
    w.push_back(b1);
    Menu * m1 = new Menu(200,40,200,40, s,4);
    Menu * m2 = new Menu(410,40,200,40,s2,4);
    w.push_back(m1);
    w.push_back(m2);
    Textbox * t1 = new Textbox(20,260,200,40,"");
    Textbox * t2 = new Textbox(20,310,200,40, "");
    w.push_back(t1);
    w.push_back(t2);
    event(ev);
    while(gin >> ev){
        Clear();
        for(Widget* v:w){
            if(v->is_selected(ev)){
                v->handle(ev);
            }
            if (ev.keycode==key_tab && v->is_selected(ev))
                    {
                        Kiiras(v);
                    }
            v->draw();
        }
        if(ev.keycode==key_enter && t1->is_selected(ev))
            {
                m1->add_element(t1->Konvertalas());
            }
        if(ev.keycode==key_enter && t2->is_selected(ev))
            {
                m2->add_element(t2->Konvertalas());
            }
        m1->draw();
        m2->draw();
        if(ev.keycode==key_insert)
        {
            gout << move_to(250,260) << color(255,255,255) << box(200,40);
            gout << move_to(254,284) << color(255,0,0) << text(m1->getElement(m1->Atad()));
            gout << move_to(250,310) << color(255,255,255) << box(200,40);
            gout << move_to(254,334) << color(255,0,0) << text(m2->getElement(m1->Atad()));

        }
        gout << refresh;
    }
}
