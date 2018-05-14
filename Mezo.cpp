#include "Mezo.h"
#include "iostream"
using namespace genv;

Mezo::Mezo(int x, int y):Widget(x,y){
}

Mezo::~Mezo(){
}

int Mezo::xmeret() {
    return pxmeret;
}

int Mezo::ymeret() {
    return pymeret;
}

void Mezo::rajzol(){
    gout << move_to(x(),y()) << color(125,125,125) << box(xmeret(),ymeret());
    gout << move_to(x()+2,y()+2) << color(0,0,0) << box(xmeret()-4,ymeret()-4);
}

bool Mezo::rajtavan(int evpx, int evpy) {
    return x() < evpx && evpx < x() + xmeret()
        && y() < evpy && evpy < y() + ymeret();
}

bool Mezo::aktivalas(){
    return aktiv;
}

void Mezo::inaktivalas(){
    aktiv = false;
}

void Mezo::esemeny(genv::event ev){
    if (ev.type == ev_mouse && ev.button == btn_left ){
        aktiv = true;
        aktivalas();


    }
}


