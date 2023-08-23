#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
    Player(bool coma, const  sf::Vector2f& initialPosition);//всё работает ошибок нет
    void move(bool leftOrRight);
    void applyGravity(const std::vector<sf::Vector2f>& groundPositions);
    void update(std::vector<sf::Vector2f> groundPositions);
    void draw(sf::RenderWindow& window);

private:
    bool command;
    sf::RectangleShape playerBlock;
    sf::Vector2f position;
    float hp;
    float velocityY;
    bool onGround;
    static const float GRAVITY;
};