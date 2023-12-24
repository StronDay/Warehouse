#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

#include "../box/box.h"
#include "../item/item.h"

using namespace std;

class Warehouse
{
private:

    vector<Box> _boxes;
    vector<Item> _items;
    
public:

    Warehouse();
    ~Warehouse();

    void addBox(Box& box);
    void addItem(Item& item);

    friend ostream& operator<<(ostream& os, Warehouse& warehouse);
    void printItems();

    bool seacrhItem(string name);
};
