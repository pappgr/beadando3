#ifndef TEXTBOX_HPP_INCLUDED
#define TEXTBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class Textbox : public Widget {
protected:
    bool _focused;
    std::string szoveg;
    bool hosszabb;
public:
    Textbox(int x, int y, int sx, int sy, std::string szov);
    virtual std::string Konvertalas();
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool is_selected(genv::event ev);
};

#endif // TEXTBOX_HPP_INCLUDED

