//
// Created by elsai on 17/06/2023.
//

#ifndef PROVASFML_DISPLAY_H
#define PROVASFML_DISPLAY_H

class Display {
public:
    virtual ~Display() {}

    virtual void draw() = 0;
};

#endif //PROVASFML_DISPLAY_H
