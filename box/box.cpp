#include "box.h"

Box::Box(unsigned int height, unsigned int width, unsigned int length) 
    : _height(height), _width(width), _length(length)
{}

ostream& operator<<(ostream& os, Box& box) 
{ 
    os << "Размер: " << box._height << "(высота) " << box._width << "(ширина) " << box._length << "(длинна)";
    return os; 
} 