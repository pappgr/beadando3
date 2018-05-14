#include "Szamkijelzo.h"
#include <sstream>
#include "iostream"
using namespace genv;
using namespace std;


Szamkijelzo::Szamkijelzo(int x, int y):Widget(x,y){
}

Szamkijelzo::~Szamkijelzo(){
}

string Szamkijelzo::tostring(int n){
    stringstream sst;
    string s;
    sst << n;
    sst >> s;
    return s;
}

void Szamkijelzo::rajzol(){
    gout << move_to(x(),y()) << color(125,125,125) << box(kxmeret,kymeret);
    string sszam = tostring(psz);
    gout.load_font("LiberationSans-Regular.ttf", 32);
    gout << move_to(x()+4,y()+4) << color (0,0,0) << text(sszam);
}

int Szamkijelzo::SzamKI(){
    return psz;
}

void Szamkijelzo::SzamBE(int x){
    psz = x;
}

void Szamkijelzo::esemeny(genv::event ev){
}
