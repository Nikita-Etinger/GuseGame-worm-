#include "Game.h"
#include "Landscape.h"

Game::Game() {
    
}

void Game::run() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_W, WINDOW_H), "Guse of war");
    font.loadFromFile("arial.ttf");
    landSpace.generateLandscape();
    sf::Vector2f initialPlayerPosition(300.0f, 0.0f); // Ваше начальное значение
    players.push_back(Player(1, initialPlayerPosition));
    //for (int i = 0; i < 3; i++) {
    //    players.push_back(new Player(1));
    //    players.push_back(new Player(0));
    //}

    while (window.isOpen()) {

        processInput(window);
        update();
        render(window);
    }
}

void Game::processInput(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    // Чтение ввода пользователя 
    // Обработка ввода и передача команд игроку
    //player.processInput(); // Передача команд игроку
}

void Game::update() {
    for (auto& p : players) {
        p.update(landSpace.getCoordinate());
    }
    
}

void Game::render(sf::RenderWindow& window) {

    window.clear();
    landSpace.draw(window);
    for (auto& p : players) {
        p.draw(window);
    }
    window.display();

    
}