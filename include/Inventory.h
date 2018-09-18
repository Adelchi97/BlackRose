//
// Created by Elena Faillace on 07/07/2018.
//

#ifndef BLACKROSE_INVENTORY_H
#define BLACKROSE_INVENTORY_H

#include "management/ResourceHolder.h"
#include "Objects/Object.h"
#include <iostream>

//template <typename object>
class Inventory {
public:
    Inventory();

    bool addItem(std::shared_ptr<Object> item);
    std::shared_ptr<Object> getElement(Object::Type type);
    std::shared_ptr<Object> findElement(Object::Type type);

private:
    int maxElements = 12;
    int iter;
    std::vector<std::shared_ptr<Object>> slots;
};




//vettore di oggetti, ogni personaggio ha un inventario

#endif //BLACKROSE_INVENTORY_H
