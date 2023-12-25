#include "item.h"

Item::Item(string name, unsigned int height, unsigned int width, unsigned int length) 
    : _name(name), _height(height), _width(width), _length(length)
{
    _size = _height * _width * _length;
}

ostream& operator<<(ostream& os, Item& item) 
{ 
    os << "Товар: " << item._name << endl;
    os << "Размер: " << item._height << "(высота) " << item._width << "(ширина) " << item._length << "(длинна)"; 
    return os; 
} 

string Item::getName() {

    string result = _name;

    for (char& c : result) {
        c = std::tolower(c);
    }

    return result;
}

unsigned int Item::getSize() 
{
    return _size;
}