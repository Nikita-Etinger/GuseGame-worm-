#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Config.h"

class Landscape {
public:
    void generateLandscape();
    void draw(sf::RenderWindow& window);
    std::vector<sf::Vector2f> getCoordinate();

private:
    sf::RectangleShape groundBlock;
    std::vector<sf::Vector2f> groundPositions;
    
};