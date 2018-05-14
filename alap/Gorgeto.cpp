#include "Gorgeto.h"

using namespace genv;

Gorgeto::Gorgeto(int x,int y): Widget(x,y){
}

Gorgeto::~Gorgeto(){
}

void Gorgeto::rajzol(){
    gout << move_to(x(),y()) << color(0,0,0) << box(20,124);
    gout << move_to(x(),y()+eltolas) << color(125,125,125) << box(pxmeret,pymeret);
}

void Gorgeto::esemeny(genv::event ev){
}

void Gorgeto::meret(int vmeret){
    pymeret = (124*4)/vmeret;
    if (pymeret > 124){
        pymeret = 124;
    }
}

void Gorgeto::elmozdul(int vmeret,int irany){
    int lepesek = vmeret - 4;
    int ut = 124 - pymeret;
    eltolas = eltolas + ut/lepesek * irany;
}
