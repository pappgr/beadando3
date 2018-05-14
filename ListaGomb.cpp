#include "ListaGomb.h"
using namespace genv;

ListaGomb::ListaGomb(int x, int y): Widget(x,y){
}

ListaGomb::~ListaGomb(){
}

void ListaGomb::rajzol(){
}

bool ListaGomb::rajtavan(int evpx, int evpy) {
    return x() < evpx && evpx < x() + pxmeret
        && y() < evpy && evpy < y() + pymeret;
}

bool ListaGomb::sz1(){
    return szektor1;
}

bool ListaGomb::sz2(){
    return szektor2;
}

bool ListaGomb::sz3(){
    return szektor3;
}

bool ListaGomb::sz4(){
    return szektor4;
}

void ListaGomb::inaktivalas(){
    szektor1 = false;
    szektor2 = false;
    szektor3 = false;
    szektor4 = false;
}

void ListaGomb::esemeny(genv::event ev){
    if (ev.type == ev_mouse && ev.button == btn_left && rajtavan(ev.pos_x, ev.pos_y)){
        if (y() <= ev.pos_y and ev.pos_y <= y()+42){
                szektor1 = true;
        }
        else if (y()+42 < ev.pos_y and ev.pos_y <= y()+84){
                szektor2 = true;
        }
        else if (y()+84 < ev.pos_y and ev.pos_y <= y()+126){
                szektor3 = true;
        }
        else if (y()+126 < ev.pos_y and ev.pos_y <= y()+168){
                szektor4 = true;
        }
    }
}
