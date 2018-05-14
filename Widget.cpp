#include "Widget.h"
using namespace genv;

Widget::Widget(int x, int y): px(x), py(y){
}

Widget::~Widget(){
}

int Widget::x() {
    return px;
}

int Widget::y() {
    return py;
}



