#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>

using namespace std;


class Menu : public Widget {
protected:
    vector<string> s;
    bool _focused;
    int _v_size;
    int index;
    int elem;
    int elso;
public:
    Menu(int x, int y, int sx, int sy, vector<string> S, int e);
    virtual std::string Konvertalas();
    virtual int Atad();
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool is_selected(genv::event ev);
    virtual void add_element(string h);
    virtual string getElement(int n);
};

#endif // MENU_HPP_INCLUDED
