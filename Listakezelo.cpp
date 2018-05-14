#include "Listakezelo.h"
#include "Widget.h"
#include "Fel.h"
#include "Le.h"
#include "Listakijelzo.h"
#include "ListaGomb.h"
#include "Gorgeto.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;
using namespace genv;

Listakezelo::Listakezelo(int x, int y, vector<string> lista):
        Widget(x,y),listaj(x,y),listag(x,y),f(x+163,y),l(x+163,y+148),gor(x+163,y+22),v(lista){
}


Listakezelo::~Listakezelo(){
}

void Listakezelo::fajlbair(){
    ofstream fajl;
    fajl.open("aktualis_ertek.txt",fstream::app);
    int a = listaj.valasztasKI();
    fajl << v[a-1] << endl;
    fajl.close();
}

void Listakezelo::elemhozzaad(string a){
    v.push_back(a);
}

void Listakezelo::rajzol(){
    if (egyszerfut){
        listaj.rajzolegyeb();
        egyszerfut = false;
    }
    listaj.rajzol();
    f.rajzol();
    l.rajzol();
    gor.rajzol();
}

void Listakezelo::kijelzokalibrator(){
    listaj.vectorBE(v);
    if (v.size() <=4 and v.size() >= 1){
        listaj.magassag(v.size());
    }
    else if (v.size() > 4){
        listaj.magassag(4);
    }
    else if(v.size() < 1){
        listaj.magassag(1);
    }
}

void Listakezelo::valasztaskalibrator(){
    if (listag.sz1()){
        eltol = listaj.eltolasKI();
        listaj.valasztasBE(1+eltol);
        listag.inaktivalas();
    }
    else if(listag.sz2()){
        eltol = listaj.eltolasKI();
        listaj.valasztasBE(2+eltol);
        listag.inaktivalas();
    }
    else if(listag.sz3()){
        eltol = listaj.eltolasKI();
        listaj.valasztasBE(3+eltol);
        listag.inaktivalas();
    }
    else if(listag.sz4()){
        eltol = listaj.eltolasKI();
        listaj.valasztasBE(4+eltol);
        listag.inaktivalas();
    }
}


void Listakezelo::esemeny(genv::event ev){
    kijelzokalibrator();
    f.esemeny(ev);
    l.esemeny(ev);
    gor.meret(v.size());
    if (f.aktivalas() or (ev.type == ev_mouse && ev.button == btn_wheelup)){
        eltol = listaj.eltolasKI();
        eltol = eltol - 1;
        if (v.size()<5){
            f.inaktivalas();
        }
        else if (eltol < 0){
            f.inaktivalas();
        }
        else{
            gor.elmozdul(v.size(),-1);
            listaj.eltolasBE(eltol);
            f.inaktivalas();
        }
    }
    if (l.aktivalas() or (ev.type == ev_mouse && ev.button == btn_wheeldown)){
        eltol = listaj.eltolasKI();
        eltol = eltol + 1;
        if (v.size()<5){
            l.inaktivalas();
        }
        else if (eltol > v.size()-4){
            l.inaktivalas();
        }
        else{
            gor.elmozdul(v.size(),+1);
            listaj.eltolasBE(eltol);
            l.inaktivalas();
        }
    }
    listag.esemeny(ev);
    valasztaskalibrator();
    if(ev.type == ev_key and ev.keycode == key_space){
        fajlbair();
    }
}
