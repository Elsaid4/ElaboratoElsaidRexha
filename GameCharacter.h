//
// Created by elsai on 17/06/2023.
//

#ifndef PROVASFML_GAMECHARACTER_H
#define PROVASFML_GAMECHARACTER_H


#include "SFML/Graphics/CircleShape.hpp"

class GameCharacter {
public:
    GameCharacter();
    GameCharacter(int x, int y);
    ~GameCharacter();
    sf::CircleShape draw();

    float getX() const;

    void setX(int x);

    float getY() const;

    void setY(int y);

private:
    float x,y;
};


#endif //PROVASFML_GAMECHARACTER_H
