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

        // ����� ��� ��������� ��������� needUpdate
    bool getNeedUpdate();

    bool getUpdatePosition();

private:
    bool needUpdate=1; // �������� ��� �������� ������������� ����������
    void applyCollision(const sf::FloatRect& groundBounds, sf::Vector2f& movement);
    bool command;
    sf::RectangleShape playerBlock;
    float hp;
    float velocityY;
    bool onGround;
    bool shootingMode; // ���� ������ ��������
    bool shootingModeStepOne=false;
    bool turnOf=false; //����� ����
    static const float GRAVITY;
    //���� ���������� ������ ����� ����� ������, ���� ��������� �������
    std::vector<float> powerDirection;
    sf::Vector2f oldPosition;
    sf::Vector2f newPosition;
};