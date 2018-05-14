#include "Le.h"
using namespace genv;

Le::Le(int x, int y):Gomb(x,y){
}

Le::~Le(){
}

void Le::rajzol(){
    Gomb::rajzol();
    gout << color (255,255,255);
    int k = 19;
    for (int i = 0; i < ymeret()/2-1; i++){
        k = k - 2;
        for (int j = 1; j < k; j++){
            gout << move_to(x()+xmeret()/2-9+i+j, y()+6+i) << dot;
        }
    }
}

bool Le::aktivalas(){
    return aktiv;
}

void Le::inaktivalas(){
    aktiv = false;
}

void Le::esemeny(genv::event ev){
    if (ev.type == ev_mouse && ev.button == btn_left && rajtavan(ev.pos_x, ev.pos_y)){
        aktiv = true;
        aktivalas();
    }
}
