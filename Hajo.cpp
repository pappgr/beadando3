#include "Hajo.h"
#include "iostream"
using namespace genv;

Hajo::Hajo(int x, int y, int r, int g, int b, int db):Widget(x,y){
}

Hajo::~Hajo(){
}

int Hajo::xmeret() {
    return pxmeret;
}

int Hajo::ymeret() {
    return pymeret;
}

void Hajo::rajzol(){
    for (int i=0; i<db; i++) {
    gout << move_to(x()+(xmeret()*i),y()+(ymeret()*i)) << color(r,g,b) << box(xmeret(),ymeret());
    gout << move_to(x()+2+(xmeret()*i),y()+2+(ymeret()*i)) << color(0,0,0) << box(xmeret()-4,ymeret()-4);
    }
}




