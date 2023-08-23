// Game.h
#pragma once

#include <iostream> 
#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Landscape.h"
#include "Player.h"
#include <vector>

class Game {
public:

    Game();
    void run();

private:
    Landscape landSpace;
    std::vector<Player> players;
    sf::Font font;
    void processInput(sf::RenderWindow& window);
    void update();
    void render(sf::RenderWindow& window);

};