//
// Created by elsai on 17/06/2023.
//

#ifndef PROVASFML_OBSERVER_H
#define PROVASFML_OBSERVER_H


class Observer {
public:
    virtual ~Observer() {}

    virtual void update() = 0;
    virtual void attach() = 0;
    virtual void detach() = 0;

};


#endif //PROVASFML_OBSERVER_H
