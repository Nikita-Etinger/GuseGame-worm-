#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Config.h"

class Landscape {
public:



    void generateLandscape();


    void draw(sf::RenderWindow& window);
    std::vector<sf::FloatRect>& getBlocks();

private:
    std::vector<sf::FloatRect> blockRectsBuf;
    sf::VertexArray groundVertices;
    std::vector<sf::RectangleShape> groundBlocks;
};