//
// Created by Ludovico on 06/09/2018.
//
#include "../include/Inventory.h"

Inventory::Inventory(){
    for (int i = 0; i < maxElements; i++){
        arrayItems[i] = NULL;
    }
}

bool Inventory::addItem(Object* item) {
    for (int i = 0; i < maxElements; i++){
        if (arrayItems[i] == NULL) {
            arrayItems[i] = item;
            return true;
        }
    }
    return false;
}

bool Inventory::getElement(int pos, Object &item) const {
    if (pos >= 0 && pos < maxElements && arrayItems[pos] != NULL ) {
        item = *arrayItems[pos];
        return true;
    }
    return false;
}


int Inventory::getMaxElements() const {
    return maxElements;
}


//it has to make spawn the Item on the map and remove from inventory
bool Inventory::removeItem(int pos, Object &item) {

    if (arrayItems[pos] != NULL) {
        arrayItems[pos] = NULL;
        return true;
    }
    return false;
}

