#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameCharacter.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 800), "Gioco");


    auto* p = new GameCharacter(100, 100);

    // Loop
    while (window.isOpen()){

        sf::Event event;
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                p->setX(p->getX() + 1);
                break;
            default:
                break;
        }

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear();
        window.draw(p->draw());
        window.display();
    }

    return 0;
}
