//
// Created by elsai on 03/07/2023.
//

#ifndef PROVASFML_GAME_H
#define PROVASFML_GAME_H

#include <SFML/Graphics.hpp>


class Game {
public:
    Game();
    virtual ~Game();

    void spawnEnemy();

    void update();
    void pollEvents();
    void updateMousePos();
    void updateEnemies();

    void render();
    void renderEnemies();

    const bool running() const { return window->isOpen(); }

private:
    void initVariables();
    void initWindow();
    void initEnemies();

    sf::Vector2i mousePosWindow;

    sf::RenderWindow* window{};
    sf::Event event{};
    sf::VideoMode videoMode;

    sf::RectangleShape enemy;
    std::vector<sf::RectangleShape> enemies;

    int points;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;

};


#endif //PROVASFML_GAME_H
