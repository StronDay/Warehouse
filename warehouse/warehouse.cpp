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

    int id = 1;

    for (auto box: warehouse._boxes) {
        os << endl << "Коробка №" <<  id << endl << box << endl;
        os << "----------------------------------------";

        id++;
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
        if (item.getName() == name) result = true;
    }

    return result;
}

unsigned int Warehouse::getItemSize(string name) 
{
    for (char& c : name) {
        c = tolower(c);
    }

    unsigned int result;

    for (auto item: _items) {
        if (item.getName() == name) result = item.getSize();
    }

    return result;
}

unsigned int Warehouse::getBoxSize(unsigned int id) 
{
    return _boxes[id].getSize();
}

unsigned int Warehouse::getSuitableBox(unsigned int size) 
{
    unsigned int id = 1;

    unsigned int buffSize = 0;
    unsigned int minId = 0;


    for (auto box: _boxes) {
        if (box.getSize() >= size && (buffSize == 0 || box.getSize() < buffSize)) {
            minId = id;
            buffSize = box.getSize();
        }

        id++;
    }

    return minId == 0 ? 0: minId;
}

unsigned int Warehouse::howNeedBoxes(unsigned int idBox, string nameItem, unsigned int numberItems)
{
    return (numberItems * getItemSize(nameItem) + getBoxSize(idBox - 1) - 1) / getBoxSize(idBox - 1);
}