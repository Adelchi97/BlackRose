//
// Created by Ludovico on 14/09/2018.
//

#ifndef BLACKROSE_SUBJECT_H
#define BLACKROSE_SUBJECT_H


#include "Observer.h"

class Subject {

protected:
    virtual ~Subject(){};

public:

    virtual void registerObserver( std::shared_ptr<Observer> observer){} ;
    virtual void removeObserver ( std::shared_ptr<Observer> observer) {};
    virtual void notifyObservers () const = 0;

};


#endif //BLACKROSE_SUBJECT_H
