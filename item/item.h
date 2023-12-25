#pragma once

#include <iostream>
#include <string>

using namespace std;

class Item {

private:

    string _name;

    unsigned int _height;
    unsigned int _width;
    unsigned int _length;

    unsigned int _size;

public:

    Item(string name, unsigned int height, unsigned int width, unsigned int length);

    friend ostream& operator<<(ostream& os, Item& item);

    string getName();
    unsigned int getSize();
};