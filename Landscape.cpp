#include "Landscape.h"
#include <random>

void Landscape::generateLandscape() {
    const int groundHeight = WINDOW_H - BLOCK_SIZE * 50; // Высота земли (50 блоков)

    // Генерация земли и блоков ниже земли
    for (int y = WINDOW_H; y >= 0; y -= BLOCK_SIZE) {
        for (int x = 0; x < WINDOW_W / BLOCK_SIZE; ++x) {
            if (y > groundHeight) {
                groundPositions.push_back(sf::Vector2f(static_cast<float>(x * BLOCK_SIZE), static_cast<float>(y)));
            }
            else {
                groundPositions.push_back(sf::Vector2f(static_cast<float>(x * BLOCK_SIZE), static_cast<float>(groundHeight)));
            }
        }
    }

    groundBlock.setSize(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
    groundBlock.setFillColor(sf::Color::Green);
}

void Landscape::draw(sf::RenderWindow& window) {

    for (auto& position : groundPositions) {
        groundBlock.setPosition(position);
        window.draw(groundBlock);
    }
    
}

std::vector<sf::Vector2f> Landscape::getCoordinate()
{
    return groundPositions;
}
