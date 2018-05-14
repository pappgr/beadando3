#include "Gomb.h"
using namespace genv;

Gomb::Gomb(int x, int y):Widget(x,y){
}

Gomb::~Gomb(){
}

int Gomb::xmeret() {
    return pxmeret;
}

int Gomb::ymeret() {
    return pymeret;
}

void Gomb::rajzol(){
    gout << move_to(x(),y()) << color(125,125,125) << box(xmeret(),ymeret());
}

bool Gomb::rajtavan(int evpx, int evpy) {
    return x() < evpx && evpx < x() + xmeret()
        && y() < evpy && evpy < y() + ymeret();
}


