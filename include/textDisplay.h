//
// Created by Elena Faillace on 28/07/2018.
//

#ifndef BLACKROSE_TEXTDISPLAY_H
#define BLACKROSE_TEXTDISPLAY_H

#include <string>
#include "Entity.h"

class textDisplay: public Entity {
public:
    textDisplay();

    void setString(std::string mstring);
    void update();

private:
    std::string string = "default";
};


#endif //BLACKROSE_TEXTDISPLAY_H
