#include "Szamkezelo.h"
#include "Widget.h"
#include "Fel.h"
#include "Le.h"
#include "Szamkijelzo.h"
#include <iostream>
#include <fstream>

using namespace genv;
using namespace std;

Szamkezelo::Szamkezelo(int x, int y, int e, int minimum, int maximum):
    Widget(x,y),szamj(x,y),f(x+83,y),l(x+83,y+22),ertek(e),maxi(maximum),mini(minimum){
}


Szamkezelo::~Szamkezelo(){
}

void Szamkezelo::fajlbair(){
    ofstream fajl;
    fajl.open("aktualis_ertek.txt",fstream::app);
    int a = szamj.SzamKI();
    fajl << a << endl;
    fajl.close();
}

void Szamkezelo::rajzol(){
    szamj.rajzol();
    f.rajzol();
    l.rajzol();
}



void Szamkezelo::esemeny(genv::event ev){
    if (egyszeri){
        szamj.SzamBE(ertek);
        egyszeri=false;
    }
    f.esemeny(ev);
    l.esemeny(ev);
    if (f.aktivalas() or (ev.type ==ev_key && (ev.keycode == key_up or ev.keycode == key_pgup))){
        int a = szamj.SzamKI();
        a = a + 1;
        if (a >= maxi){
            f.inaktivalas();
        }
        else{
            szamj.SzamBE(a);
            f.inaktivalas();
        }
    }
    if (l.aktivalas() or (ev.type ==ev_key && (ev.keycode == key_down or ev.keycode == key_pgdn))){
        int a = szamj.SzamKI();
        a = a - 1;
        if (a <= mini){
            l.inaktivalas();
        }
        else{
            szamj.SzamBE(a);
            l.inaktivalas();
        }
    }
    if(ev.type == ev_key and ev.keycode == key_space){
        fajlbair();
    }
}

