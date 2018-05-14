#include "Listakijelzo.h"
#include "vector"
using namespace std;
using namespace genv;

Listakijelzo::Listakijelzo(int x, int y): Widget(x,y){
}

Listakijelzo::~Listakijelzo(){
}

void Listakijelzo::rajzolszoveg(){
    if (szorzo >= 1){
        gout << move_to(x()+4,y()+4) << color (0,0,0) << text(lista[i]);
        if (szorzo >= 2){
            gout << move_to(x()+4,y()+42+4) << color (0,0,0) << text(lista[i+1]);
            if (szorzo >= 3){
                gout << move_to(x()+4,y()+84+4) << color (0,0,0) << text(lista[i+2]);
                if (szorzo >= 4){
                    gout << move_to(x()+4,y()+126+4) << color (0,0,0) << text(lista[i+3]);
                }
            }
        }
    }
}

void Listakijelzo::szinez(int a){
    gout << move_to(x(),y()+(a*42)) << color(0,0,255) << box(pxmeret,42);
}

void Listakijelzo::rajzolszinez(){
    if(kivalasztott-1 == i){
        szinez(0);
    }
    else if(kivalasztott-1 == i+1 and lista.size() > 1){
        szinez(1);
    }
    else if(kivalasztott-1 == i+2 and lista.size() > 2){
        szinez(2);
    }
    else if(kivalasztott-1 == i+3 and lista.size() > 3){
        szinez(3);
    }
}

void Listakijelzo::rajzolegyeb(){
    gout.load_font("LiberationSans-Regular.ttf", 12);
    gout << move_to(20,550) <<color(255,255,255) << text("Fajlba iras: 'space'");
}

void Listakijelzo::rajzol(){
    gout << move_to(x(),y()) << color(125,125,125) << box(pxmeret,pymeret);
    gout.load_font("LiberationSans-Regular.ttf", 28);
    rajzolszinez();
    rajzolszoveg();
}

void Listakijelzo::magassag(int x){
    szorzo = x;
}

void Listakijelzo::vectorBE(vector<string> v){
    lista = v;
}

void Listakijelzo::eltolasBE(int x){
    i=x;
}

int Listakijelzo::eltolasKI(){
    return i;
}

void Listakijelzo::valasztasBE(int x){
    kivalasztott = x;
}

int Listakijelzo::valasztasKI(){
    return kivalasztott;
}

void Listakijelzo::esemeny(genv::event ev){
}
