//
// Created by elsai on 03/07/2023.
//

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <random>

Game::Game(){
    initVariables();
    initWindow();
    initEnemies();
}

Game::~Game() {
    delete window;
}

void Game::render() {
    window->clear(sf::Color::Black);

    // Draw game objects
    renderEnemies();

    window->display();
}

void Game::renderEnemies() {
    for(auto& e : enemies){
        window->draw(e);
    }
}

void Game::update() {
    pollEvents();

    updateMousePos();

    updateEnemies();

    //std::cout<<"Mouse pos: " << sf::Mouse::getPosition(*window).x << " " << sf::Mouse::getPosition(*window).y << std::endl;
}

void Game::pollEvents() {
    while (window->pollEvent(event)){
        switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                    window->close();
                }
                break;
            default:
                break;
        }
    }

}

void Game::updateMousePos() {
    //Aggiorno la posizione del mouse relativo a window (Vector2i)
    mousePosWindow = sf::Mouse::getPosition(*window);
}

void::Game::updateEnemies() {
    if(enemies.size() < maxEnemies) {
        if (enemySpawnTimer >= enemySpawnTimerMax) {
            spawnEnemy();
            enemySpawnTimer = 0.f;
        }else{
            enemySpawnTimer += 1.f;
        }
    }

    for(auto& e : enemies){
        e.move(0.f, 1.f);
    }
}

void Game::initVariables() {
    window = nullptr;

    points = 0;
    enemySpawnTimerMax = 1000.f;
    enemySpawnTimer = enemySpawnTimerMax;
    maxEnemies = 5;
}

void Game::initWindow() {
    videoMode.height = 800;
    videoMode.width = 800;
    window = new sf::RenderWindow(videoMode, "Gioco");
    window->setFramerateLimit(60);
}

void Game::initEnemies() {
    enemy.setPosition(10.f, 10.f);
    enemy.setSize(sf::Vector2f(100.f, 100.f));
    enemy.setFillColor(sf::Color::Red);
    enemy.setOutlineColor(sf::Color::Green);
    enemy.setOutlineThickness(1.f);
}

void Game::spawnEnemy() {
    enemy.setPosition(
            static_cast<float>(std::rand() % static_cast<int>(window->getSize().x - enemy.getSize().x)),
            0.f
            );
    enemy.setFillColor(sf::Color::Green);
    enemies.push_back(enemy);
}
