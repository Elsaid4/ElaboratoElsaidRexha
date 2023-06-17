//
// Created by elsai on 17/06/2023.
//

#include "GameCharacter.h"
#include <SFML/Graphics.hpp>

GameCharacter::GameCharacter() : x(0), y(0){}

GameCharacter::GameCharacter(int x, int y) : x(x), y(y){}


float GameCharacter::getX() const {
    return x;
}

void GameCharacter::setX(int x) {
    GameCharacter::x = x;
}

float GameCharacter::getY() const {
    return y;
}

void GameCharacter::setY(int y) {
    GameCharacter::y = y;
}

GameCharacter::~GameCharacter() {
    delete this;
}

sf::CircleShape GameCharacter::draw() {
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(x, y);
    return shape;
}
