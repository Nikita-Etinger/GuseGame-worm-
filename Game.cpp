#include "Game.h"
#include "Landscape.h"
#include <iostream>

Game::Game() {
    
    activePlayerIndex = 0; // �������� � ������� ������
}

void Game::run() {
    sf::Clock clock;
    landSpace = Landscape();
    sf::RenderWindow window(sf::VideoMode(WINDOW_W, WINDOW_H), "Guse of war");
    window.setFramerateLimit(120);
    font.loadFromFile("arial.ttf");
    landSpace.generateLandscape();
    players.push_back(Player(1, sf::Vector2f(300.0f, 0.0f)));
    players.push_back(Player(1, sf::Vector2f(700.0f, 0.0f)));
    // ...

    while (window.isOpen()) {
        time = clock.getElapsedTime().asMicroseconds(); //���� ��������� ����� � �������������
        clock.restart(); //������������� �����
        time = time/2000 ; //�������� ����
        processInput(window);
        update(time);
        render(window);
    }
}

void Game::processInput(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Enter) {
                // ���� � ����� �������� ��� ��������� ������
                players[activePlayerIndex].enterShootingMode();
            }
        }
    }

    // ��������� ���������� ������������ ��� ��������� (������� �� ������)
    if (!players[activePlayerIndex].isShootingMode()) {
        // ��������� ����������� (A, D)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            players[activePlayerIndex].move(true,time);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            players[activePlayerIndex].move(false, time);
        }
    }
    else {
        // ��������� ������ ����������� � ���� ��������
        // ...
    }
}


void Game::update(float time) {
    for (auto& p : players) {
        if (p.getUpdatePosition()) {
            p.update(landSpace.getBlocks(), time);
        }
    }

    //if (players[activePlayerIndex].getHp() <= 0.0f || players[activePlayerIndex].getTurnOf()) {
    //    nextTurn();
    //}
    frames++;
    if (fpsClock.getElapsedTime().asSeconds() >= 1.0f) {
        std::cout << "FPS: " << frames << std::endl;
        frames = 0;
        fpsClock.restart();
    }
    // ���������� �������� � ������ ����
}

void Game::render(sf::RenderWindow& window) {
    window.clear();
    landSpace.draw(window);
    for (auto& p : players) {
        p.draw(window);
    }
    window.display();
    // ...
}

void Game::nextTurn() {
    // ������� � ���������� ������
    do {
        activePlayerIndex = (activePlayerIndex + 1) % players.size();
    } while (players[activePlayerIndex].getHp() <= 0.0f); // ���������� ������� �������

    // �������������� �������� ��� ������ ���� ������ ������
    players[activePlayerIndex].resetState(); // ���������� ��������� ( ��������� ����� ��������)
}
