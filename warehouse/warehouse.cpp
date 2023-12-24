#include "warehouse.h"

Warehouse::Warehouse()
{
}

Warehouse::~Warehouse()
{
}

void Warehouse::addBox(Box& box) 
{
    _boxes.push_back(box);
}

void Warehouse::addItem(Item& item) 
{
    _items.push_back(item);
}

ostream& operator<<(ostream& os, Warehouse& warehouse) 
{
    os << endl << endl << "--------------------------------------------------"<< endl;
    os << "Склад:";
    os << endl;
    
    for (auto item: warehouse._items) {
        os << endl << item << endl;
        os << "----------------------------------------";
    }

    os << endl;

    for (auto box: warehouse._boxes) {
        os << endl << "Коробка" << endl << box << endl;
        os << "----------------------------------------";
    }
    os << endl << "--------------------------------------------------" << endl << endl;

    return os;
}

void Warehouse::printItems()
{
    for (auto item: _items) {
        cout << endl << item << endl;
        cout << "----------------------------------------";
    }
}

bool Warehouse::seacrhItem(string name) 
{
    for (char& c : name) {
        c = tolower(c);
    }

    bool result = false;

    for (auto item: _items) {
        cout << name << endl << item.getName();
        if (item.getName() == name) result = true;
    }

    return result;
}