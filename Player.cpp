#include "Player.h"
#include "Config.h"
#include <iostream>

const float Player::GRAVITY = 0.1f;

Player::Player(bool coma, const  sf::Vector2f& initialPosition)
    : command(coma), onGround(false), velocityY(0.0f) {
    powerDirection.push_back(0);
    powerDirection.push_back(0);
    playerBlock.setSize(sf::Vector2f(20.0f, 20.0f));
    playerBlock.setFillColor(sf::Color::Blue);
    playerBlock.setPosition(initialPosition.x, initialPosition.y);
    hp = 100.0f;
    shootingMode = false; // »значально не в режиме стрельбы
}

void Player::move(bool leftOrRight,float time) {
    if (!shootingMode) {
        if (leftOrRight) {
            playerBlock.move(-0.1f*time, 0.0f);
        }
        else {
            playerBlock.move(0.1f * time, 0.0f);
        }
    }
}

void Player::enterShootingMode() {
    shootingMode = true;
    // вход в режим стрельбы
    
}
void Player::ShootingMode(bool upOrDown) {
    //выбор направлени€ и силы выстрела
    if (shootingModeStepOne) {
        //выбор направлени€
        powerDirection[0] += (upOrDown) ? 0.1: -0.1;
    }
    else {
        //выбор силы выстрела
        powerDirection[1] += (upOrDown) ? 0.1 : -0.1;

    }


}
//std::vector<float> Player::getPowerDirection() {
//
//    return std::vector<float>(power,direction);
//}

bool Player::isShootingMode() const {
    return shootingMode;
}
bool Player::getTurnOf() {//получение состо€ни€ хода игрока
    return turnOf;
};
void Player::applyGravity(std::vector<sf::FloatRect>& landscape, float time) {
    float playerBottomY = playerBlock.getPosition().y + playerBlock.getSize().y;
    float groundLevel = landscape[0].top - playerBlock.getSize().y;

    onGround = playerBottomY >= groundLevel;

    if (onGround) {
        playerBlock.setPosition(playerBlock.getPosition().x, groundLevel);
        velocityY = 0.0f;
    }
    else {
        velocityY += GRAVITY;
        playerBlock.move(0.0f, velocityY * time);
    }
}

void Player::update(std::vector<sf::FloatRect>& landscape, float time) {
    if (hp > 0.0f) {
        // —охран€ем текущую позицию перед обновлением
        oldPosition = playerBlock.getPosition();

        // ѕримен€ем гравитацию только если нужно обновление и игрок не на земле
        if (needUpdate && !onGround) {
            applyGravity(landscape, time);
        }

        sf::Vector2f movement(0.0f, 0.0f);

        if (!shootingMode) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                move(true, time);
                movement.x -= 1.0f;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                move(false, time);
                movement.x += 1.0f;
            }
        }

        for (const auto& groundBounds : landscape) {
            applyCollision(groundBounds, movement);
        }

        playerBlock.move(movement);
        // —охран€ем новую позицию после обновлени€
        newPosition = playerBlock.getPosition();

        // ƒополнительные проверки дл€ режима стрельбы
        if (shootingMode) {
            // ...
        }
    }
}
void Player::applyCollision(const sf::FloatRect& groundBounds, sf::Vector2f& movement) {
    sf::FloatRect playerBounds = playerBlock.getGlobalBounds();

    if (playerBounds.intersects(groundBounds)) {
        if (movement.x < 0) {
            playerBlock.setPosition(groundBounds.left + groundBounds.width, playerBlock.getPosition().y);
        }
        else if (movement.x > 0) {
            playerBlock.setPosition(groundBounds.left - playerBlock.getSize().x, playerBlock.getPosition().y);
        }
    }
}

void Player::draw(sf::RenderWindow& window) {
    if (hp > 0.0f) {
        window.draw(playerBlock);
    }
}
bool Player::getUpdatePosition() {
    return oldPosition == newPosition;
}
void Player::resetState()
{
    shootingMode = false;
}
float Player::getHp() const {
    return hp;
}