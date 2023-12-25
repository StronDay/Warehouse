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

    Item item1("chair", 20, 25, 35);
    Item item2("wardrobe", 80, 60, 60);
    Item item3("table", 40, 40, 40);

    Box box1(60, 60, 60);
    Box box2(40, 40, 40);
    Box box3(20, 25, 45); 

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

            {
                unsigned int itemSize = warehouse.getItemSize(name);
                unsigned int idSuitableBox = warehouse.getSuitableBox(itemSize);

                if (idSuitableBox == 0) {
                    cout << "Подходящей коробки для фасовки товара нету" << endl << endl;
                    break;
                }

                cout << "Товар надо разместить в коробке №" << idSuitableBox << endl;
                cout << "Кол-во необходимых коробок: " << warehouse.howNeedBoxes(idSuitableBox, name, number) << endl << endl;

                break;
            }

            break;

        case 0:

            is_exit = true;
            break;

        default:
        
            cout << "Такой пункт в меню отсутсвует" << endl << endl;
            break;
        }
    }

    return 0;
}