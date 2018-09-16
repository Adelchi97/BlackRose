//
// Created by Elena Faillace on 07/07/2018.
//

#ifndef BLACKROSE_INVENTORY_H
#define BLACKROSE_INVENTORY_H

#include "Objects/Object.h"

//template <typename object>
class Inventory {
public:
    Inventory();
    Inventory(const Object& right);

    //TODO cosa è questo?? un doppio puntatore D:
    Inventory(Object **arrayItems);

    Object& operator=(const Object& right);
    virtual ~Inventory(){}
    //TODO puntatori!!
    bool addItem(Object* item);
    bool getElement(int pos, Object& item) const;
    bool removeItem(int pos, Object& item);
    int getMaxElements() const;


protected:
    static const int maxElements = 12;
    //TODO altri puntatori halp
    Object *arrayItems[maxElements];
};




//vettore di oggetti, ogni personaggio ha un inventario

#endif //BLACKROSE_INVENTORY_H
