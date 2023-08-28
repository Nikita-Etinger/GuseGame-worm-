#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Player {
public:
    Player(bool coma, const sf::Vector2f& initialPosition);
    void move(bool leftOrRight, float time);
    void enterShootingMode();
    bool isShootingMode() const;
    void applyGravity(std::vector<sf::FloatRect>& landscape, float time);
    void update(std::vector<sf::FloatRect>& landscape, float time);
    void draw(sf::RenderWindow& window);
    float getHp() const;
    bool getTurnOf();
    void resetState();
    void ShootingMode(bool upOrDown);
    //std::vector<int>getPowerDirection();
    void setNeedUpdate(bool needUpdateState);

        // Метод для получения состояния needUpdate
    bool getNeedUpdate();

    bool getUpdatePosition();

private:
    bool needUpdate=1; // Параметр для контроля необходимости обновления
    void applyCollision(const sf::FloatRect& groundBounds, sf::Vector2f& movement);
    bool command;
    sf::RectangleShape playerBlock;
    float hp;
    float velocityY;
    bool onGround;
    bool shootingMode; // Флаг режима стрельбы
    bool shootingModeStepOne=false;
    bool turnOf=false; //конец хода
    static const float GRAVITY;
    //любо управление делать через класс игрока, либо отдельным классом
    std::vector<float> powerDirection;
    sf::Vector2f oldPosition;
    sf::Vector2f newPosition;
};