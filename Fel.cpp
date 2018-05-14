#include "Fel.h"
#include "Szamkijelzo.h"
#include "vector"

using namespace genv;

Fel::Fel(int x, int y):Gomb(x,y){
}

Fel::~Fel(){
}

void Fel::rajzol(){
    Gomb::rajzol();
    gout << color (255,255,255);
    int k = -1;
    for (int i = 0; i < ymeret()/2-1; i++){
        k = k + 2;
        for (int j = 1; j < k; j++){
            gout << move_to(x()+xmeret()/2-1-i+j, y()+4+i) << dot;
        }
    }
}

bool Fel::aktivalas(){
    return aktiv;
}

void Fel::inaktivalas(){
    aktiv = false;
}

void Fel::esemeny(genv::event ev){
    if (ev.type == ev_mouse && ev.button == btn_left && rajtavan(ev.pos_x, ev.pos_y)){
        aktiv = true;
        aktivalas();
    }
}
