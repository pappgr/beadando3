#include "Textbox.hpp"
#include "graphics.hpp"
#include <iostream>
using namespace genv;
using namespace std;

Textbox::Textbox(int x, int y, int sx, int sy, std::string _szoveg)
    : Widget(x,y,sx,sy)
{
    _focused=false;
    szoveg=_szoveg;
    hosszabb=false;
}

string Textbox::Konvertalas()
{
    return szoveg;
}


void Textbox::draw()
{
    gout << move_to(_x, _y) << color(255,0,0) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    gout<< move_to(_x+_size_x/2-gout.twidth(szoveg)/2, _y+_size_y/2+(gout.cascent()+gout.cdescent())/2)<<color(255,255,255)<<text(szoveg);

    if(_focused)
    {

    }
    else
    {
        gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
        gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
        gout<< move_to(_x+_size_x/2-gout.twidth(szoveg)/2, _y+_size_y/2+(gout.cascent()+gout.cdescent())/2)<<color(255,255,255)<<text(szoveg);

    }
}

void Textbox::handle(event ev)
{
    if(_focused)
    {
        if(gout.twidth(szoveg)<_size_x-20)
        {
            if(ev.type==ev_key && ev.keycode>0 && ev.keycode<255 && !(ev.keycode==key_enter))
            {
                int szam;
                szam=ev.keycode;
                szoveg.push_back(szam);
            }
        }
        /*else if(gout.twidth(szoveg)>_size_x-20){
            if(ev.type==ev_key && ev.keycode>0 && ev.keycode<255 && !(ev.keycode==key_enter))
            {
                int szam;
                szam=ev.keycode;
                szoveg.push_back(szam);
                for(int i=0;i<szoveg.size();i++){
                    szoveg[i]=szoveg[i+1];
                }
            }
        } */
        if(ev.type==ev_key && ev.keycode==key_delete)
            if(szoveg.length()!=0)
                szoveg.pop_back();
    }
}

bool Textbox::is_selected(event ev)
{
    if (ev.pos_x > _x && ev.pos_x < _x+_size_x && ev.pos_y > _y && ev.pos_y < _y+_size_y && ev.button==btn_left){
        _focused = true;
    }
    if(!(ev.pos_x > _x && ev.pos_x < _x+_size_x && ev.pos_y > _y && ev.pos_y < _y+_size_y) && ev.button==btn_left){
        _focused = false;
    }
        return _focused;
}
