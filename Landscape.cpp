#include "Landscape.h"
#include "Config.h"


void Landscape::generateLandscape() {
    const int groundHeight = WINDOW_H - BLOCK_SIZE * 50; // Высота земли (50 блоков)

    sf::VertexArray vertices(sf::Quads);

    for (int y = WINDOW_H; y >= 0; y -= BLOCK_SIZE) {
        for (int x = 0; x < WINDOW_W / BLOCK_SIZE; ++x) {
            sf::Vertex v1(sf::Vector2f(float(x * BLOCK_SIZE), float(std::min(y, groundHeight))), sf::Color::Green);
            sf::Vertex v2(sf::Vector2f(float((x + 1) * BLOCK_SIZE), float(std::min(y, groundHeight))), sf::Color::Green);
            sf::Vertex v3(sf::Vector2f(float((x + 1) * BLOCK_SIZE), float(y)), sf::Color::Green);
            sf::Vertex v4(sf::Vector2f(float(x * BLOCK_SIZE), float(y)), sf::Color::Green);

            vertices.append(v1);
            vertices.append(v2);
            vertices.append(v3);
            vertices.append(v4);
        }
    }

    groundVertices = vertices;
}

std::vector<sf::FloatRect>& Landscape::getBlocks(){
    blockRectsBuf.clear();

    for (size_t i = 0; i < groundVertices.getVertexCount(); i += 4) {
        // Получаем координаты вершин текущего блока
        float blockLeft = groundVertices[i].position.x;
        float blockTop = groundVertices[i].position.y;
        float blockRight = groundVertices[i + 1].position.x;
        float blockBottom = groundVertices[i + 2].position.y;

        // Создаем прямоугольник для текущего блока и добавляем его в массив
        blockRectsBuf.push_back(sf::FloatRect(blockLeft, blockTop, blockRight - blockLeft, blockBottom - blockTop));
    }

    return blockRectsBuf;
}
void Landscape::draw(sf::RenderWindow& window) {
    window.draw(groundVertices);
}