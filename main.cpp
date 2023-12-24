#include <iostream>
#include <vector>

#include <algorithm>
#include <cctype>

#include "box/box.h"
#include "item/item.h"
#include "warehouse/warehouse.h"

using namespace std;

int main() {

    bool is_exit = false;
    unsigned int response;

    Item item1("стул", 20, 25, 35);
    Item item2("шкаф", 60, 60, 60);
    Item item3("стол", 40, 40, 40);

    Box box1(20, 25, 35);
    Box box2(60, 60, 60);
    Box box3(40, 40, 40); 

    Warehouse warehouse;

    warehouse.addItem(item1);
    warehouse.addItem(item2);
    warehouse.addItem(item3);

    warehouse.addBox(box1);
    warehouse.addBox(box2);
    warehouse.addBox(box3);

    while(!is_exit) {

        cout << "--------------------" << endl;
        cout << " Выйти - (0)" << endl;
        cout << " Информация о складе - (1)" << endl << endl;
        cout << " Добавить товар - (2)" << endl;
        cout << " Добавить коробку - (3)" << endl << endl;
        cout << " Сделать поставку товаров - (4)" << endl;
        cout << "--------------------" << endl;

        string name = "";
            
        unsigned int height;
        unsigned int width;
        unsigned int length;
        unsigned int number;

        cout << " > ";
        cin >> response;

        switch (response)
        {
        case 1:
            cout << warehouse;
            break;

        case 2:

            cout << "название > ";
            cin >> name;

            cout << "высота > ";
            cin >> height;

            cout << "ширина > ";
            cin >> width;

            cout << "длинна > ";
            cin >> length;
            cout << endl;

            {
                Item item(name, height, width, length);
                warehouse.addItem(item);
            }

            break;

        case 3:

            cout << "высота > ";
            cin >> height;

            cout << "ширина > ";
            cin >> width;

            cout << "длинна > ";
            cin >> length;
            cout << endl;

            {
                Box box(height, width, length);
                warehouse.addBox(box);
            }

            break;

        case 4:

            cout << "название товара > ";
            cin >> name;

            cout << "кол-во > ";
            cin >> number;
            cout << endl;

            if (!warehouse.seacrhItem(name)) {
                cout << "Такой товар отсутсвует" << endl << endl;
                break;
            }

            break;

        case 0:

            is_exit = true;
            break;

        default:
        
            is_exit = true;
            break;
        }
    }

    return 0;
}