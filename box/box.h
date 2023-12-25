#pragma once

#include <iostream>
#include <string>

using namespace std;

class Box {

private:

    unsigned int _height;
    unsigned int _width;
    unsigned int _length;

    unsigned int _size;

public:

    Box(unsigned int height, unsigned int width, unsigned int length);

    friend ostream& operator<<(ostream& os, Box& box);

    unsigned int getSize();
};