//
// Created by Ludovico on 06/09/2018.
//
#include "../include/Inventory.h"

Inventory::Inventory(){
    /*
    for (int i = 0; i < maxElements; i++){
        arrayItems[i] = NULL;
    }
     */
    iter = 0;
}

bool Inventory::addItem(std::shared_ptr<Object> item) {

    if(slots.size() <= maxElements) {
        slots.emplace_back(item);
        return true;
    } else
        return false;
}

std::shared_ptr<Object> Inventory::getElement(Object::Type type) {

    std::shared_ptr<Object> element = slots[iter];
    for(int i =0; i<slots.size(); i++) {
        if(slots[iter]->type == type) {
            element = slots[iter];
            break;
        }
        iter = (iter + 1)% slots.size();
    }
    slots.erase(slots.begin() + iter);

    if(element == nullptr)
        std::cout<<"errore nel get element"<<std::endl;
    return element;
}

std::shared_ptr<Object> Inventory::findElement(Object::Type type) {

    std::shared_ptr<Object> element = slots[iter];
    for(int i =0; i<slots.size(); i++) {
        if(slots[iter]->type == type) {
            element = slots[iter];
            break;
        }
        iter = (iter + 1)% slots.size();
    }

    if(element == nullptr)
        std::cout<<"errore nel find element"<<std::endl;
    return element;
}
/*
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
*/
