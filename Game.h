#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "Landscape.h"

class Game {
public:
    Game();
    void run();


private:
    sf::Font font;
    Landscape landSpace;
    std::vector<Player> players;
    int activePlayerIndex; // Индекс активного игрока
    float time;
    int frames = 0;
    sf::Clock clock;
    sf::Clock fpsClock;
    
    void processInput(sf::RenderWindow& window);
    void update(float time);
    void render(sf::RenderWindow& window);
    void nextTurn(); // Переход к следующему игроку
};