//
// Created by Ludovico on 14/09/2018.
//

#ifndef BLACKROSE_OBSERVER_H
#define BLACKROSE_OBSERVER_H

class Observer{

protected:

    virtual ~Observer(){};

public:

    virtual void update() = 0;

};

#endif //BLACKROSE_OBSERVER_H
