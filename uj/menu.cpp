#include "menu.hpp"
#include "graphics.hpp"
#include <iostream>
#include <sstream>
#include <vector>
using namespace genv;
using namespace std;

Menu::Menu(int x, int y, int sx, int sy, vector<string> S, int e)
    : Widget(x,y,sx,sy)
{
    s=S;
    _focused=false;
    index=0;
    if (e > s.size()){
        e=s.size();
    }
    elem=e;
    elso=0;
}

string Menu::Konvertalas()
{
    return s[elso];
}

int Menu::Atad()
{
    return elso;
}

void Menu::add_element(string h)
{
    if(h!="")
    {
    s.push_back(h);
    }
}

void Menu::draw()
{
    if(s.size()>0 && elem>0){
    gout << move_to(_x, _y) << color(0,255,0) << box(_size_x, _size_y);
    gout << move_to(_x+4,_y+_size_y/2+4) << color(0,0,0) << text(s[elso]);
    gout << move_to(_x+_size_x-_size_x/3,_y) << color(0,0,255) << box(_size_x/3, _size_y);
    gout << move_to(_x+_size_x-_size_x/6,_y) << color(255,255,255) << line(0,_size_y-4);
    gout << move_to(_x+_size_x-_size_x/6,_y+_size_y-2) << color(255,255,255) << line(-_size_x/6,-_size_y/2);
    gout << move_to(_x+_size_x-_size_x/6,_y+_size_y-2) << color(255,255,255) << line(_size_x/6,-_size_y/2);
    }
    if(_focused){
        gout << move_to(_x, _y) << color(255,0,0) << box(_size_x, _size_y);
        gout << move_to(_x+4,_y+_size_y/2+4) << color(0,0,0) << text(s[elso]);
        gout << move_to(_x+_size_x-_size_x/3,_y) << color(0,0,255) << box(_size_x/3, _size_y);
        gout << move_to(_x+_size_x-_size_x/6,_y) << color(255,255,255) << line(0,_size_y-4);
        gout << move_to(_x+_size_x-_size_x/6,_y+_size_y-2) << color(255,255,255) << line(-_size_x/6,-_size_y/2);
        gout << move_to(_x+_size_x-_size_x/6,_y+_size_y-2) << color(255,255,255) << line(_size_x/6,-_size_y/2);
        for(int i=0; i<elem && i<s.size(); i++){
            gout << move_to(_x, _y+(i+1)*_size_y) << color(255,255,255) << box(_size_x, _size_y);
            gout << move_to(_x+4,_y+_size_y/2+4+(i+1)*_size_y) << color(0,0,0) << text(s[index+i]);
        }
        }
}

void Menu::handle(event ev)
{
    if(_focused){
        if(s.size()>2)
        {
            if(ev.button==btn_wheeldown && !(index==s.size()-elem)){
            index++;
            }
        }

            if(ev.button==btn_wheelup && !(index==0)){
                index--;
            }
        if(s.size()>0){
        for(int j=0; j<elem && j<s.size(); j++){
            if(ev.pos_x>_x && ev.pos_x<_x+_size_x && ev.pos_y>_y+(j+1)*_size_y && ev.pos_y<_y+(j+2)*_size_y){
                gout << move_to(_x+_size_x, _y+(j+1)*_size_y) << box(_size_x/3, _size_y);
                gout << move_to(_x+_size_x, _y+(j+1)*_size_y+_size_y/2) << color (255,0,0) << line(_size_x/3-2, 0);
                gout << move_to(_x+_size_x, _y+(j+1)*_size_y+_size_y/2) << color (255,0,0) << line(_size_x/5,_size_y/3);
                gout << move_to(_x+_size_x, _y+(j+1)*_size_y+_size_y/2) << color (255,0,0) << line(_size_x/5,-_size_y/3);
                gout << move_to(_x, _y+(j+1)*_size_y) << color(0,255,0) << box(_size_x, _size_y);
                gout << move_to(_x+4,_y+_size_y/2+4+(j+1)*_size_y) << color(0,0,0) << text(s[index+j]);
                if(ev.button==btn_left)
                {
                    elso=index+j;
                    _focused=false;
                }
            }
        }
        }
    }
}
bool Menu::is_selected(event ev)
{
    if(s.size()>0){
    if (ev.pos_x>_x+_size_x-_size_x/3 && ev.pos_x<_x+_size_x && ev.pos_y>_y && ev.pos_y<_y+_size_y && ev.button==btn_left){
        _focused=true;
    }
    if (!(ev.pos_x>_x && ev.pos_x<_x+_size_x && ev.pos_y>_y && ev.pos_y<_y+(elem+1)*_size_y)&& ev.button==btn_left) {
        _focused=false;
    }
    }
    return _focused;
}
string Menu::getElement(int n)
{
    return s[n];
}

