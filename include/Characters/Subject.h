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

    virtual void registerObserver( Observer* o) = 0;
    virtual void removeObserver ( Observer* o) = 0;
    virtual void notifyObservers () const = 0;

};


#endif //BLACKROSE_SUBJECT_H
