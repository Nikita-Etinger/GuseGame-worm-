#include "Player.h"
#include "Config.h"

const float Player::GRAVITY = 0.5f;

Player::Player(bool coma,const  sf::Vector2f& initialPosition)
    : command(coma), onGround(false), velocityY(0.0f) {
    playerBlock.setSize(sf::Vector2f(20.0f, 20.0f));
    playerBlock.setFillColor(sf::Color::Blue);
    playerBlock.setPosition(initialPosition.x, initialPosition.y);
    hp = 100.0f;
}

void Player::move(bool leftOrRight) {
    if (leftOrRight) {
        playerBlock.move(-5.0f, 0.0f);
    }
    else {
        playerBlock.move(5.0f, 0.0f);
    }
}

void Player::applyGravity(const std::vector<sf::Vector2f>& groundPositions) {
    float playerCenterX = playerBlock.getPosition().x + playerBlock.getSize().x / 2.0f;
    float playerBottomY = playerBlock.getPosition().y + playerBlock.getSize().y;

    onGround = false;

    for (auto& groundPos : groundPositions) {
        float groundBlockTopY = groundPos.y;

        if (playerBottomY >= groundBlockTopY) {
            onGround = true;
            playerBlock.setPosition(playerBlock.getPosition().x, groundBlockTopY - playerBlock.getSize().y);
            velocityY = 0.0f;
            break;
        }
    }

    if (!onGround) {
        if (playerBlock.getPosition().y + velocityY < groundPositions[0].y - playerBlock.getSize().y) {
            velocityY += GRAVITY;
            playerBlock.move(0.0f, velocityY);
        }
        else {
            playerBlock.setPosition(playerBlock.getPosition().x, groundPositions[0].y - playerBlock.getSize().y);
            velocityY = 0.0f;
            onGround = true;
        }
    }
}

void Player::update(std::vector<sf::Vector2f> groundPositions) {
    //логика обновления игрока
    applyGravity(groundPositions); // Применяем гравитацию и проверяем столкновения с землей
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(playerBlock);
}