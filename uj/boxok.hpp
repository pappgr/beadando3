#ifndef BOXOK_HPP_INCLUDED
#define BOXOK_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class Boxok : public Widget {
protected:
    bool _focused;
    int szam;
    int lk;
    int ln;
public:
    Boxok(int x, int y, int sx, int sy, int _lk, int _ln);
    virtual std::string Konvertalas();
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool is_selected(genv::event ev);
};


#endif // BOXOK_HPP_INCLUDED
